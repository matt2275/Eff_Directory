#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
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

void calculate_efficiency(){


  TFile *f_mumu_mc = new TFile("efficiency_nominal.root");
   TH1F *h_total = (TH1F*) f_mumu_mc->Get("Mu0_Open_pt_total");
   TH1F *h_pass = (TH1F*) f_mumu_mc->Get("Mu0_Open_pt_pass");
   
   auto ratio_mc = (TH1D*)h_pass->Clone("ratio_mc");
   ratio_mc->Divide(h_total);
   
   TEfficiency* grl=0 ;
   gStyle->SetOptStat(0);
   TCanvas *c = new TCanvas("c", "c",0,0,600,600);
   TPad *pad1 = new TPad("pad1",";;#epsilon(p_{T})",0,0.334,1,1);
   TPad *pad2 = new TPad("pad2",";#epsilon(p_{T});Data/MC",0,0.03,1,0.33);
   pad1->SetGrid();
   pad2->SetGrid();
   pad1->Draw();
   pad2->Draw();
   pad1->cd();
   
   
         grl = new TEfficiency(*h_pass,*h_total);
         grl->SetLineColor(2);
         grl->SetMarkerStyle(8);
         grl->SetMarkerColor(2);
         //grl->SetTitle(h_total->GetTitle());
         grl->Draw();
   
   
   TFile *f_mumu_data = new TFile("/Users/md/Documents/GGToTauTau/muonstudy/eff_conti/data/continuum_eff/efficiency_nominal.root");
   TH1F *h_totald = (TH1F*) f_mumu_data->Get("Mu0_Open_pt_total");
   TH1F *h_passd = (TH1F*) f_mumu_data->Get("Mu0_Open_pt_pass");
   auto ratio_data = (TH1D*)h_passd->Clone("ratio_data");
   ratio_data->Divide(h_totald);
   TEfficiency* grld=0 ;
   
  // TCanvas *cd = new TCanvas("cd", "cd",0,0,600,600);
   
   grld = new TEfficiency(*h_passd,*h_totald);
   grld->SetLineColor(4);
   grld->SetMarkerStyle(8);
   grld->SetMarkerColor(4);
   //grld->SetTitle(h_totald->GetTitle());
   grld->Draw( "pe same");
   
   TLegend *leg = new TLegend(0.7,0.7,0.9,0.9);
   leg->AddEntry(grl,"GGToMuMu_MC","lep");
   leg->AddEntry(grld,"GGToMuMu_Data","lep");
   leg->Draw();
   pad2->cd();
   /*TGraphAsymmErrors * gra=0 ;
   gra = new TGraphAsymmErrors (ratio_data,ratio_mc);
   gra->SetLineColor(1);
   gra->SetMarkerStyle(20);
   gra->SetMarkerColor(1);
   gra->Draw("APE");
   gra->GetYaxis()->SetRangeUser(0,1);*/
   auto ratio_h = (TH1D*)ratio_data->Clone("ratio");
   ratio_h->Divide(ratio_mc);
   ratio_h->SetMarkerStyle(8);
   ratio_h->SetMarkerColor(1);
   ratio_h->Draw();
   c->cd();
   c->Update();
   
}
