#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <iostream>
#include <fstream>
#include <TH2.h>
#include <TH1.h>
#include <string>
#include <TMath.h>
#include <vector>

#include <TStyle.h>
#include <TFile.h>
#include <TNtuple.h>
#include <TROOT.h>
#include <TSystem.h>
#include <TBuffer.h>
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TMath.h"
#include "RooPlot.h"
using namespace RooFit;
using namespace std;

void variable_comp(){

   TFile *mc_f = new TFile("/Users/md/Documents/GGToTauTau/muonstudy/eff_conti/efficiency_nominal.root");
   TFile *data_f = new TFile("/Users/md/Documents/GGToTauTau/muonstudy/efficiency_nominal.root");
   int nbins =8;
   TH1F * massall_mc_h[nbins];
   TH1F * massall_data_h[nbins];
   for (int l = 0; l<nbins; l++){
      massall_mc_h[l] = (TH1F*)mc_f->Get(Form("massall_%d_bin", l));
      massall_data_h[l] = (TH1F*)data_f->Get(Form("massall_%d_bin", l));
      
   }
   
   TH1F* pt_mucol_mc = (TH1F*) mc_f->Get("pt_mucol");
   TH1F* eta_mucol_mc = (TH1F*) mc_f->Get("eta_mucol");
   TH1F* phi_mucol_mc = (TH1F*) mc_f->Get("phi_mucol");
   
   TH1F* pt_mumu_mc = (TH1F*) mc_f->Get("pt_mumu");
   TH1F* eta_mumu_mc = (TH1F*) mc_f->Get("eta_mumu");
   TH1F* phi_mumu_mc = (TH1F*) mc_f->Get("phi_mumu");
   
   
   TH1F* pt_mucol_data = (TH1F*) data_f->Get("pt_mucol");
   TH1F* eta_mucol_data = (TH1F*) data_f->Get("eta_mucol");
   TH1F* phi_mucol_data = (TH1F*) data_f->Get("phi_mucol");
   
   TH1F* pt_mumu_data = (TH1F*) data_f->Get("pt_mumu");
   TH1F* eta_mumu_data = (TH1F*) data_f->Get("eta_mumu");
   TH1F* phi_mumu_data = (TH1F*) data_f->Get("phi_mumu");
   
   
   TCanvas *c = new TCanvas("c","c", 0, 0, 1200, 800);
   c->Divide(3,2);
   c->cd(1);
   pt_mucol_mc->SetLineColor(kRed);
   pt_mucol_mc->SetMarkerColor(kRed);
   pt_mucol_mc->SetBins(100,0.0,20);
   pt_mucol_mc->DrawNormalized("COLZ");
   pt_mucol_data->SetBins(100,0.0,20.0);
   pt_mucol_data->DrawNormalized("COLZ" "SAME");
   
   c->cd(2);
   eta_mucol_mc->SetLineColor(kRed);
   eta_mucol_mc->SetMarkerColor(kRed);
   eta_mucol_mc->DrawNormalized();
   eta_mucol_data->DrawNormalized("SAME");
   
   c->cd(3);
   phi_mumu_mc->SetLineColor(kRed);
   phi_mumu_mc->SetMarkerColor(kRed);
   phi_mumu_mc->DrawNormalized();
   phi_mumu_data->DrawNormalized("SAME");
   
   
   c->cd(4);
   pt_mumu_mc->SetLineColor(kRed);
   pt_mumu_mc->SetMarkerColor(kRed);
   pt_mumu_mc->DrawNormalized();
   pt_mumu_data->DrawNormalized("SAME");
   
   c->cd(5);
   eta_mumu_mc->SetLineColor(kRed);
   eta_mumu_mc->SetMarkerColor(kRed);
   eta_mumu_mc->DrawNormalized();
   eta_mumu_data->DrawNormalized("SAME");
   
   c->cd(6);
   phi_mumu_mc->SetLineColor(kRed);
   phi_mumu_mc->SetMarkerColor(kRed);
   phi_mumu_mc->DrawNormalized();
   phi_mumu_data->DrawNormalized("SAME");

   TCanvas *cm = new TCanvas("cm","cm", 0, 0, 1200, 800);
   cm->Divide(2,2);
   for(int i=1; i<=4; ++i)
      {
      cm->cd(i);
      massall_mc_h[i-1]->SetLineColor(kRed);
      massall_mc_h[i-1]->SetMarkerColor(kRed);
      massall_mc_h[i-1]->DrawNormalized();
      massall_data_h[i-1]->DrawNormalized("SAME");
      
      }
   TCanvas *cm1 = new TCanvas("cm1","cm1", 0, 0, 1200, 800);
   cm1->Divide(2,2);
   for(int i=5; i<=8; ++i)
      {
      cm1->cd(i-4);
      massall_mc_h[i-1]->SetLineColor(kRed);
      massall_mc_h[i-1]->SetMarkerColor(kRed);
      massall_mc_h[i-1]->DrawNormalized();
      massall_data_h[i-1]->DrawNormalized("SAME");
      
      }
      
  /* cm->cd(1);
   massall_mc_h[1]->SetLineColor(kRed);
   massall_mc_h[1]->SetMarkerColor(kRed);
   massall_mc_h[1]->DrawNormalized();
   massall_data_h[1]->DrawNormalized("SAME");
   
   cm->cd(2);
   massall_mc_h[2]->SetLineColor(kRed);
   massall_mc_h[2]->SetMarkerColor(kRed);
   massall_mc_h[2]->DrawNormalized();
   massall_data_h[2]->DrawNormalized("SAME");
   
   cm->cd(3);
   massall_mc_h[3]->SetLineColor(kRed);
   massall_mc_h[3]->SetMarkerColor(kRed);
   massall_mc_h[3]->DrawNormalized();
   massall_data_h[3]->DrawNormalized("SAME");
   
   cm->cd(4);
   massall_mc_h[4]->SetLineColor(kRed);
   massall_mc_h[4]->SetMarkerColor(kRed);
   massall_mc_h[4]->DrawNormalized();
   massall_data_h[4]->DrawNormalized("SAME");
   
   cm->cd(5);
   massall_mc_h[5]->SetLineColor(kRed);
   massall_mc_h[5]->SetMarkerColor(kRed);
   massall_mc_h[5]->DrawNormalized();
   massall_data_h[5]->DrawNormalized("SAME");
   
   cm->cd(6);
   massall_mc_h[6]->SetLineColor(kRed);
   massall_mc_h[6]->SetMarkerColor(kRed);
   massall_mc_h[6]->DrawNormalized();
   massall_data_h[6]->DrawNormalized("SAME");
   
   cm->cd(7);
   massall_mc_h[7]->SetLineColor(kRed);
   massall_mc_h[7]->SetMarkerColor(kRed);
   massall_mc_h[7]->DrawNormalized();
   massall_data_h[7]->DrawNormalized("SAME");
   
   cm->cd(8);
   massall_mc_h[8]->SetLineColor(kRed);
   massall_mc_h[8]->SetMarkerColor(kRed);
   massall_mc_h[8]->DrawNormalized();
   massall_data_h[8]->DrawNormalized("SAME");
   
   */
      
   
   
}
