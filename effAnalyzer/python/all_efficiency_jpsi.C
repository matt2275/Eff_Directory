// Author Muhammad Alibordi
// GG To TauTau analysis

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

void all_efficiency_jpsi(){
    
    TFile *fIn1 = new TFile("trktrig_eff_UPCSMuon_InclusiveJpsi_MC.root");
    TFile *fIn2 = new TFile("trktrig_eff_UPCSMuon_InclusiveJpsi_Data.root");
    //HLT_HIUPC_SingleMu0_NotMBHF2AND_v*
    TH1F* h_pt_denom_mc = (TH1F*) fIn1->Get("eff/h_pt_probe_all");
    TH1F* h_pt_num_mc = (TH1F*) fIn1->Get("eff/h_pt_probe_pass");
    //HLT_HIUPC_SingleMuOpen_NotMBHF2AND_v*
    TH1F* h_pt_denom_data = (TH1F*) fIn2->Get("eff/h_pt_probe_all");
    TH1F* h_pt_num_data = (TH1F*) fIn2->Get("eff/h_pt_probe_pass");
    
    TCanvas* c_pt = new TCanvas("c_pt","c_pt");
    c_pt->SetGrid(1,1);
    c_pt->cd();
    TH2F* h_pt_axis = new TH2F("h_pt_axis",";p_{T} (GeV);#epsilon_{trigger}(p_{T})",15,0,20,15,0,1.2);
    h_pt_axis->GetYaxis()->SetTitleOffset(0.98);
    h_pt_axis->Draw();
    
    TEfficiency* h_pt_eff = new TEfficiency(*h_pt_num_mc, *h_pt_denom_mc);
    h_pt_eff->SetLineColor(kRed);
    h_pt_eff->SetMarkerColor(kRed);
    h_pt_eff->Draw("pe same");
    
    TEfficiency* h_pt_eff_data = new TEfficiency(*h_pt_num_data, *h_pt_denom_data);
    h_pt_eff_data->SetLineColor(kBlue);
    h_pt_eff_data->SetMarkerColor(kBlue);
    h_pt_eff_data->Draw("pe same");
    
    TLegend *leg = new TLegend(0.7,0.7,0.9,0.9);
    leg->AddEntry(h_pt_eff,"MC","lep");
    leg->AddEntry(h_pt_eff_data,"Data","lep");
    leg->Draw();
    c_pt->Update();
    //c_pt->SaveAs("eff_pt_plot.root","root");

 TH1F* h_eta_denom_mc = (TH1F*) fIn1->Get("eff/h_eta_probe_all");
    TH1F* h_eta_num_mc = (TH1F*) fIn1->Get("eff/h_eta_probe_pass");
    TH1F* h_eta_denom_data = (TH1F*) fIn2->Get("eff/h_eta_probe_all");
    TH1F* h_eta_num_data = (TH1F*) fIn2->Get("eff/h_eta_probe_pass");
    TCanvas* c_eta = new TCanvas("c_eta","c_eta");
    c_eta->SetGrid(1,1);
    c_eta->cd();

    TH2F* h_eta_axis = new TH2F("h_eta_axis",";#eta;#epsilon_{trigger}(#eta)",100,-2.4,2.4,100,0,2);
    h_eta_axis->GetYaxis()->SetTitleOffset(0.98);
    h_eta_axis->Draw();
    
    TEfficiency* h_eta_eff_mc = new TEfficiency(*h_eta_num_mc, *h_eta_denom_mc);
    h_eta_eff_mc->SetLineColor(kRed);
    h_eta_eff_mc->SetMarkerColor(kRed);
   h_eta_eff_mc->Draw("pe same");
   TEfficiency* h_eta_eff_data = new TEfficiency(*h_eta_num_data, *h_eta_denom_data);
   h_eta_eff_data->SetLineColor(kBlue);
   h_eta_eff_data->SetMarkerColor(kBlue);
    h_eta_eff_data->Draw("pe same");
     
    TLegend *legeta = new TLegend(0.7,0.7,0.9,0.9);
    legeta->AddEntry(h_eta_eff_mc,"MC","lep");
    legeta->AddEntry(h_eta_eff_data,"Data","lep");
    legeta->Draw();
    c_eta->Update();



TH1F* h_phi_denom_mc = (TH1F*) fIn1->Get("eff/h_phi_probe_all");
    TH1F* h_phi_num_mc = (TH1F*) fIn1->Get("eff/h_phi_probe_pass");
    TH1F* h_phi_denom_data = (TH1F*) fIn2->Get("eff/h_phi_probe_all");
    TH1F* h_phi_num_data = (TH1F*) fIn2->Get("eff/h_phi_probe_pass");
    
    TCanvas* c_phi = new TCanvas("c_phi","c_phi");
    c_phi->SetGrid(1,1);
    c_phi->cd();

    TH2F* h_phi_axis = new TH2F("h_phi_axis",";#phi (rad);#epsilon_{trigger}(#phi)",100,-TMath::Pi(),TMath::Pi(),20,0,1);
    h_phi_axis->GetYaxis()->SetTitleOffset(0.98);
    h_phi_axis->Draw();
    
    TEfficiency* h_phi_eff_mc = new TEfficiency(*h_phi_num_mc, *h_phi_denom_mc);
    h_phi_eff_mc->SetLineColor(kRed);
    h_phi_eff_mc->SetMarkerColor(kRed);
   h_phi_eff_mc->Draw("pe same");
   
   TEfficiency* h_phi_eff_data = new TEfficiency(*h_phi_num_data, *h_phi_denom_data);
   h_phi_eff_data->SetLineColor(kBlue);
   h_phi_eff_data->SetMarkerColor(kBlue);
    h_phi_eff_data->Draw("pe same");
   
   TLegend *legphi = new TLegend(0.7,0.7,0.9,0.9);
   legphi->AddEntry(h_phi_eff_mc,"MC","lep");
   legphi->AddEntry(h_phi_eff_data,"Data","lep");
   legphi->Draw();
   c_phi->Update();
   
   TFile *outf = TFile::Open("eff_plot_jpsi.root","RECREATE");
   c_pt->Write();
   c_eta->Write();
   c_phi->Write();
   outf->Close();
}
