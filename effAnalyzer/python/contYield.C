/// \author  - Muhammad Alibordi
// Test of RooKeyPDF has ability to discriminate the background and

#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TTree.h"
#include "TH1D.h"
#include "TRandom.h"
//#include "RooJohnsonLocal.cxx"
using namespace RooFit ;
using namespace std;



void contYield(){


Int_t nbins = 100;
TChain* chain_data = new TChain("eff/eff_muon");
chain_data->Add("trktrig_eff_UPCSMuon_Continuum_MC.root");
Int_t nevt = (int)chain_data->GetEntries();
std::cout<<"Number of total events"<<nevt<<"\n";
    
    RooRealVar *trigDiMuon_all= new RooRealVar("trigDiMuon_all", "M_{l^{+}l^{-}} GeV/c^{2}",7.00,50.0);
    RooRealVar *trigDiMuon_pass= new RooRealVar("trigDiMuon_pass", "M_{l^{+}l^{-}} GeV/c^{2}",7.00,50.0);
    
    RooDataSet *data_all = new RooDataSet("data_all", "data", RooArgSet(*trigDiMuon_all), Import(*chain_data));
    RooDataSet *data_pass = new RooDataSet("data_pass", "data", RooArgSet(*trigDiMuon_pass), Import(*chain_data));
    
    RooKeysPdf *pdf_all= new RooKeysPdf("pdf_all","pdf_all",*trigDiMuon_all,*data_all,RooKeysPdf::NoMirror);
    RooKeysPdf *pdf_pass= new RooKeysPdf("pdf_all","pdf_all",*trigDiMuon_pass,*data_pass,RooKeysPdf::NoMirror);
    
    RooRealVar *nall = new RooRealVar("nall", "Number of Signal Events",140,0.,(int)chain_data->GetEntries());
    RooRealVar *npass = new RooRealVar("npass", "Number of Signal Events",140,0.,(int)chain_data->GetEntries());
    
    RooExtendPdf *llall = new RooExtendPdf("llall", "extended llall",*pdf_all,*nall);
    RooExtendPdf *llpass = new RooExtendPdf("llpass", "extended llpass",*pdf_pass,*npass);
    
    RooFitResult* fitRes_all = llall->fitTo(*data_all,Save(), Extended(1));//data_SigReg
    fitRes_all->Print("v");
    RooFitResult* fitRes_pass = llpass->fitTo(*data_pass,Save(), Extended(1));//data_SigReg
    fitRes_pass->Print("v");
    
    RooAbsReal* int_all = pdf_all->createIntegral(*trigDiMuon_all,NormSet(*trigDiMuon_all)) ;
    RooAbsReal* int_pass = pdf_pass->createIntegral(*trigDiMuon_pass,NormSet(*trigDiMuon_pass)) ;
    Double_t allIntProb = int_all->getVal();
    Double_t passIntProb =  int_pass->getVal();//(iMT_sig->getVal())*(nSig->getValV()) ;
    Double_t allEvt = (int_all->getVal())*(nall->getValV());
    Double_t allEvtErr = nall->getError()*int_all->getVal();
    Double_t passEvt = (int_pass->getVal())*(npass->getValV());
    Double_t passEvtErr = npass->getError()*int_pass->getVal();
    
    Double_t Efficiency = (passEvt/allEvt);
    Double_t EfficiencyError = sqrt((passEvtErr/passEvt)*(passEvtErr/passEvt) + (allEvtErr/allEvt)*(allEvtErr/allEvt));
    
    //cout<<" Trigger Efficiency "<< Efficiency<<" :pm:"<< EfficiencyError<<"\n";
    
    TCanvas *c = new TCanvas("c", "c",0,0,600,600);
    RooPlot* allmass = trigDiMuon_all->frame(Title("M_{l^{+}l^{-}} GeV/c^{2}"),Bins(nbins));
    data_all->plotOn(allmass,DataError(RooAbsData::SumW2));
    llall->plotOn(allmass) ;
    allmass->SetStats(0);
    allmass->Draw();
    c->SaveAs("allmass.pdf", "pdf");
    
    TCanvas *c1 = new TCanvas("c1", "c1",0,0,600,600);
    RooPlot* passmass = trigDiMuon_pass->frame(Title("M_{l^{+}l^{-}} GeV/c^{2}"),Bins(nbins));
    data_pass->plotOn(passmass,DataError(RooAbsData::SumW2));
    llpass->plotOn(passmass) ;
    passmass->SetStats(0);
    passmass->Draw();
    c1->SaveAs("passmass.pdf", "pdf");
    cout<<" Trigger Efficiency "<< Efficiency<<" :pm:"<< EfficiencyError<<"\n";


}
