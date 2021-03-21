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

void fit_dimuon_etabin(){
  
TFile *myf = TFile::Open("/Users/md/Documents/GGToTauTau/muonstudy/efficiency_nominal.root","READ");
   // TFile *myf = TFile::Open("/Users/md/Documents/GGToTauTau/muonstudy/eff_conti/efficiency_nominal_mc.root","READ");
    int nbins = 8;
    RooKeysPdf *pdf_all[nbins];
    RooKeysPdf *pdf_pass[nbins];
    TLatex *cms1[nbins];TLegend *leg[nbins];
    TH1F * massall[nbins];
    TH1F *masspass[nbins];
    RooDataHist *bindataall[nbins];
    RooDataHist *bindatapass[nbins];
    RooRealVar *nall[nbins];
    RooRealVar *npass[nbins];
    RooExtendPdf *llall[nbins];
    RooExtendPdf *llpass[nbins];
    RooFitResult* fitRes_all[nbins]; RooFitResult* fitRes_pass[nbins];
    RooAbsReal* int_all[nbins]; RooAbsReal* int_pass[nbins];
    Double_t allIntProb[nbins];
    Double_t passIntProb[nbins];
    Double_t allEvt[nbins];
    Double_t allEvtErr[nbins];
    Double_t passEvt[nbins];
    Double_t passEvtErr[nbins];
    Double_t Efficiency[nbins];
    Double_t EfficiencyError[nbins];
    RooDataSet *data_all[nbins];
    RooDataSet *data_pass[nbins];
    RooPlot* dimuon_all[nbins];
    RooPlot* dimuon_pass[nbins];
    RooRealVar *trigDiMuon_all= new RooRealVar("trigDiMuon_all", " M_{#mu^{+}#mu^{-}} (GeV/c^{2})",7.00,80.0);
    RooRealVar *trigDiMuon_pass= new RooRealVar("trigDiMuon_pass", " M_{#mu^{+}#mu^{-}} (GeV/c^{2})",7.00,80.0);
    for(int k =0 ; k < nbins; k++){
        
        massall[k] = (TH1F*)myf->Get(Form("massall_%d_bin", k));
        masspass[k] = (TH1F*)myf->Get(Form("masspass_%d_bin", k));
        bindataall[k] = new RooDataHist("bindataall", "bindata", *trigDiMuon_all, Import(*massall[k]));
        bindatapass[k] = new RooDataHist("bindatapass", "bindata", *trigDiMuon_pass, Import(*masspass[k]));
        nall[k] = new RooRealVar("nall", "Number of Signal Events in SIGNAL MC",7,(int)massall[k]->GetEntries());
        npass[k] = new RooRealVar("npass", "Number of Signal Events in SIGNAL MC",7,(int)masspass[k]->GetEntries());
        data_all[k] = (RooDataSet*)bindataall[k]->Clone("data_all");
        data_pass[k] = (RooDataSet*)bindatapass[k]->Clone("data_pass");
        
    }
    
    
    
    RooRealVar *mu= new RooRealVar("mu", "#mu", 8.0, 9.0, 20.0);
     RooRealVar *lambda = new RooRealVar("lambda", "#lambda",  0.1, 0, 10);
     RooRealVar *gamma = new RooRealVar("gamma", "#gamma",  0., -5, 5);
     RooRealVar *delta = new RooRealVar("delta", "#delta", 1., 0, 20);
    RooRealVar *muP= new RooRealVar("muP", "#mu", 8.00, 10.0, 20.0);
    RooRealVar *lambdaP = new RooRealVar("lambdaP", "#lambda",  0.1, 0, 20);
    RooRealVar *gammaP = new RooRealVar("gammaP", "#gamma",  0., -10, 10);
    RooRealVar *deltaP = new RooRealVar("deltaP", "#delta", 1., 0, 20);
     RooJohnson *johnA = new RooJohnson("johnA", "johnA", *trigDiMuon_all, *mu, *lambda, *gamma, *delta);
    RooJohnson *johnP = new RooJohnson("johnP", "johnP", *trigDiMuon_pass, *muP, *lambdaP, *gammaP, *deltaP);
    
    
    TCanvas *c = new TCanvas("c", "c",0,0,600,600);
   c->SetFillColor(10);
   c->SetBorderMode(0);
   c->SetBorderSize(0);
   c->SetFrameBorderMode(0);
   c->SetFrameLineWidth(2);
   c->SetLeftMargin(0.2);
   c->SetBottomMargin(0.1);
   c->SetFrameFillColor(0);
    gStyle->SetPalette(1) ;
    gStyle->SetOptTitle(0);
    /*gStyle->SetFrameBorderMode(0);
    gStyle->SetFrameBorderSize(1);
    gStyle->SetFrameFillColor(0);
    gStyle->SetFrameFillStyle(0);
    gStyle->SetFrameLineColor(1);
    gStyle->SetFrameLineStyle(1);
    gStyle->SetFrameLineWidth(1);
    gStyle->SetTitleSize(0.2, "t");
    gStyle->SetTitleX(0.45);
    gStyle->SetTitleY(0.999);
    gStyle->SetTitleW(0.7);
    gStyle->SetTitleH(0.24);*/
    gStyle->SetOptFile(0);
    gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
    gStyle->SetStatColor(kWhite);
    gStyle->SetStatFont(42);
    gStyle->SetStatFontSize(0.025);
    gStyle->SetStatTextColor(1);
    gStyle->SetStatFormat("6.4g");
    gStyle->SetStatBorderSize(1);
    gStyle->SetStatH(0.1);
    gStyle->SetStatW(0.15);
    for(int j =0; j<nbins; ++j)
        
    {
        //pdf_all[j]= new RooKeysPdf("pdf_all","pdf_all",*trigDiMuon_all,*data_all[j],RooKeysPdf::NoMirror);
        //pdf_pass[j]= new RooKeysPdf("pdf_all","pdf_all",*trigDiMuon_pass,*data_pass[j],RooKeysPdf::NoMirror);
        llall[j] = new RooExtendPdf("llall", "extended llall",*johnA,*nall[j]);
        llpass[j] = new RooExtendPdf("llpass", "extended llpass",*johnP,*npass[j]);

        fitRes_all[j] = llall[j]->fitTo(*data_all[j],Save(),NumCPU(8));
        fitRes_all[j]->Print("v");
        fitRes_pass[j] = llpass[j]->fitTo(*data_pass[j],Save(),NumCPU(8));
        fitRes_pass[j]->Print("v");
        
           int_all[j] = llall[j]->createIntegral(*trigDiMuon_all,NormSet(*trigDiMuon_all)) ;
           int_pass[j] = llpass[j]->createIntegral(*trigDiMuon_pass,NormSet(*trigDiMuon_pass)) ;
           allIntProb[j] = int_all[j]->getVal();
           passIntProb[j] =  int_pass[j]->getVal();
           allEvt[j] = (int_all[j]->getVal())*(nall[j]->getValV());
           allEvtErr[j] = nall[j]->getError()*int_all[j]->getVal();
           passEvt[j] = (int_pass[j]->getVal())*(npass[j]->getValV());
           passEvtErr[j] = npass[j]->getError()*int_pass[j]->getVal();
           
            Efficiency[j] = (passEvt[j]/allEvt[j]);
           EfficiencyError[j] = sqrt((passEvtErr[j]/passEvt[j])*(passEvtErr[j]/passEvt[j]) +(allEvtErr[j]/allEvt[j])*(allEvtErr[j]/allEvt[j]));
           
           cout<<" Trigger Efficiency "<< Efficiency[j]<<" :pm:"<< EfficiencyError[j]<<"\n";
        dimuon_all[j] = trigDiMuon_all->frame(Title("#bf{CMS} #it{Preliminary} , M_{#mu^{+}#mu^{-}} (GeV/c^{2}), #sqrt{s} = 5.02 TeV"),Bins(40));
        data_all[j]->plotOn(dimuon_all[j],DataError(RooAbsData::SumW2));
        llall[j]->plotOn(dimuon_all[j]) ;
        llall[j]->paramOn(dimuon_all[j]);
        llall[j]->plotOn(dimuon_all[j], RooFit::LineColor(kGreen),RooFit::Components("pdf_all"), RooFit::Name("signal"), LineWidth(2), LineStyle(4));
           // leg[j] = new TLegend(0.7,0.7,0.9,0.9);
           // leg[j]->AddEntry(dimuon_all[j]->findObject("signal"),"M_{#mu^{+}#mu^{-}}","LEP");
           // dimuon_all[j]->SetStats(0);
           // llall[j]->SetStats(0);
          dimuon_all[j]->Draw();
           // leg[j]->SetBorderSize(0);
           // leg[j]->Draw("same");
            /*cms1[j] = new TLatex(0.0, 5300, "CMS #it{Preliminary} , M_{#mu^{+}#mu^{-}} (GeV/c^{2}), #sqrt{s} = 5.02 TeV");
            cms1[j]->SetNDC(false);
            cms1[j]->SetTextColor(12);
            cms1[j]->SetTextFont(42);
            cms1[j]->SetTextSize(0.038);
            cms1[j]-> Draw();*/
            c->Update();
    gSystem->Exec("mkdir -p fittedplots");
    TString dirName = "fittedplots/";
    c->SaveAs(Form("/Users/md/Documents/GGToTauTau/muonstudy/eff_conti/fittedplots/fittedM_conti_data_%d.pdf",j));
           
        

}
    for(int l =0 ; l<nbins; ++l){
        std::cout<<"mc_eff["<<l<<"]="<<Efficiency[l]<<";"<<"\n";
         
    }
    for(int l =0 ; l<nbins; ++l){
        std::cout<<"mc_effErr["<<l<<"]="<<EfficiencyError[l]<<";"<<"\n";
         
    }
    for(int l =0 ; l<nbins; ++l){
       
         cout<<" Trigger Efficiency in"<<l<<"th bin :"<< Efficiency[l]<<" :pm:"<< EfficiencyError[l]<<"\n";
    }

}
