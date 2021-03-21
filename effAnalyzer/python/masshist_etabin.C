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


void masshist_etabin(){
    //Double_t bins[] = {-2.4,-1.8,-1.2,-0.6,0,0.6,1.2,1.8,2.4};
    //Int_t  nbins = sizeof(bins)/sizeof(Double_t) - 1;
   
    int nbins =8;
     TH1F * massall_h[nbins];
    TH1F * masspass_h[nbins];
    for (int l = 0; l<nbins; l++){
    massall_h[l] = new TH1F(Form("massall%dth_Bin", l),Form("massall%dth_Bin; M_{#mu^{+}#mu^{-}} ; Events",l),40,2.7,3.5);
    masspass_h[l] = new TH1F(Form("masspass%dth_Bin", l),Form("masspass%dth_Bin; M_{#mu^{+}#mu^{-}} ; Events",l),40,2.7,3.5);
        
    }
   //TFile *fIn1 = new TFile("trktrig_eff_UPCSMuon_InclusiveJpsi_Data.root");
   TFile *fIn1 = new TFile("trktrig_eff_UPCSMuon_InclusiveJpsi_MC.root");
//    TFile *fIn1 = new TFile("abordi_trktrig_eff.root");
    TH1F* hmllA = (TH1F*) fIn1->Get("eff/h_trigmll_all");
    TH1F* hmllP = (TH1F*) fIn1->Get("eff/h_trigmll_pass");
    TH1F* hetaA = (TH1F*) fIn1->Get("eff/h_eta_probe_all");
       
     Double_t massall, etaall, etaall2, masspass;
    
    
    
    std::cout<<"All probe events: "<<hmllA->GetEntries()<<"\n";
    std::cout<<"Pass probe events: "<<hmllP->GetEntries()<<"\n";
    //std::cout<<hetaA->GetEntries()<<"\n";
    for (int i=0 ;i<hmllA->GetEntries(); ++i)
    {
        massall = hmllA->GetRandom();
        
        etaall = hetaA->GetRandom();
        //std::cout<<massall<<"\t"<<masspass<<"\t"<<etaall<<"\n";
        if(etaall >-2.4 && etaall < -1.8){
                                    massall_h[0]->Fill(massall);
                                   
        }
        if(etaall >-1.8 && etaall < -1.2){
                                    massall_h[1]->Fill(massall);
                                   
        }
        if(etaall >-1.2 && etaall < -0.6){
                                    massall_h[2]->Fill(massall);
                                   
        }
        if(etaall >-0.6 && etaall < 0.0){
                                    massall_h[3]->Fill(massall);
                                    
        }
        if(etaall >0.0 && etaall < 0.6){
                                    massall_h[4]->Fill(massall);
                                   
        }
        if(etaall >0.6 && etaall < 1.2){
                                    massall_h[5]->Fill(massall);
                                   
        }
        if(etaall >1.2 && etaall < 1.8){
                                    massall_h[6]->Fill(massall);
                                   
        }
        if(etaall >1.8 && etaall < 2.4){
                                    massall_h[7]->Fill(massall);
                                    
        }
    }
    
    for (int i=0 ;i<hmllP->GetEntries(); ++i)
    {
        
        masspass = hmllP->GetRandom();
        etaall2 = hetaA->GetRandom();
        //std::cout<<massall<<"\t"<<masspass<<"\t"<<etaall<<"\n";
        if(etaall2 >-2.4 && etaall2 < -1.8){
                                    
                                    masspass_h[0]->Fill(masspass);
        }
        if(etaall2 >-1.8 && etaall2 < -1.2){
                                   
                                    masspass_h[1]->Fill(masspass);
        }
        if(etaall2 >-1.2 && etaall2 < -0.6){
                                    
                                    masspass_h[2]->Fill(masspass);
        }
        if(etaall2 >-0.6 && etaall2 < 0.0){
                                    
                                    masspass_h[3]->Fill(masspass);
        }
        if(etaall2 >0.0 && etaall2 < 0.6){
                                    
                                    masspass_h[4]->Fill(masspass);
        }
        if(etaall2 >0.6 && etaall2 < 1.2){
                                   
                                    masspass_h[5]->Fill(masspass);
        }
        if(etaall2 >1.2 && etaall2 < 1.8){
                                    
                                    masspass_h[6]->Fill(masspass);
        }
        if(etaall2 >1.8 && etaall2 < 2.4){
                                    
                                    masspass_h[7]->Fill(masspass);
        }
    }
    
    TFile *outf = TFile::Open("etabin_mass_jpsi_mc.root","RECREATE");
  
    for ( int m =0 ; m <nbins; m++)
       {
           
           std::cout<<massall_h[m]->GetEntries()<<"\t"<<masspass_h[m]->GetEntries()<<"\n";
           
               massall_h[m]->Write(Form("massall_%d_bin",m));
               masspass_h[m]->Write(Form("masspass_%d_bin",m));
           
           }
       outf->Close();
    
   


}
