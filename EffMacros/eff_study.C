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


void eff_study(int xbins=10, int ybins = 8, int zbins = 10){
    
    if ( ybins<1 ) ybins = xbins;
    if ( zbins<1 ) zbins = xbins;
    if ( xbins<1 ) return;
//abordi_trktrig_eff.root
    TFile *fIn1 = new TFile("trktrig_eff_UPCSMuon_Continuum_MC.root");
    //TFile *fIn1 = new TFile("abordi_trktrig_eff.root");
    TTree* mu = (TTree*)fIn1->Get("eff/eff_muon");
    Int_t n_entries = mu->GetEntries();
    std::cout<<n_entries<<"\n";
    Double_t geneta,genphi,trketa,trkphi,genpt,trkpt, Delta_pT, Delta_phi, Delta_eta;
    mu->SetBranchAddress("muon_gen_eta",&geneta);
    mu->SetBranchAddress("muon_gen_phi",&genphi);
    mu->SetBranchAddress("muon_gen_pt",&genpt);
    mu->SetBranchAddress("trkmuon_eta_all",&trketa);
    mu->SetBranchAddress("trkmuon_phi_all",&trkphi);
    mu->SetBranchAddress("trkmuon_pt_all",&trkpt);
    
    
    
    
    
    
    RooRealVar *pt=new RooRealVar("pt","p_{T} (GeV)",2.0,20);
    RooRealVar *eta=new RooRealVar("eta","#eta (a.u.)",-2.4,2.4);
    RooRealVar *phi = new RooRealVar("phi","#phi (rad)",-TMath::Pi(),TMath::Pi());
    RooArgSet vars(*pt, *eta, *phi);
    
    RooDataSet* gendata    = new RooDataSet( "gendata"   , "GEN distribution", vars );
    RooDataSet* trackingdata = new RooDataSet( "trackingdata", "RECO distribution after selections", vars );
    
    Int_t nbins =40;
    Double_t  genpt_bins[nbins], rmsreso[nbins], rmsresoErr[nbins], genpt_binsErr[nbins];
    TH1D *resolution_bin[nbins];
          for (int l = 0; l<nbins; l++){
        resolution_bin[l] = new TH1D(Form("#Delta(p_{T})%dth_Bin", l),Form("#Delta(p_{T}) %dth_Bin; #Delta(p_{T}); Events",l),nbins,-0.06,0.06);
    }
    TH2F *hresovspt = new TH2F("hresovspt", "#Delta(p_{T}) vs p_{t}^{gen};p_{T}^{gen} (GeV);#Delta(p_{T})", 100, 0.,20.0, 100, -0.1,0.1 );
    TH2F *hresoetavspt = new TH2F("hresoetavspt", "#Delta(#eta) vs p_{t}^{gen};p_{T}^{gen} (GeV);#Delta(#eta)", 100, 0.,20.0, 100,-2.4,2.4);
    TH2F *hresophivspt = new TH2F("hresophivspt", "#Delta(#phi) vs p_{t}^{gen};p_{T}^{gen} (GeV);#Delta(#phi)", 100, 0.,20.0, 100,-TMath::Pi(),TMath::Pi());
    auto eta_resolution = new TH1D("eta_resolution", "#eta resolution ; #Delta(#eta) = (#eta_{GEN}-#eta_{TRACKING})/#eta_{GEN}; Events ",  100, -0.004, 0.004);
    auto phi_resolution = new TH1D("phi_resolution", "#phi resolution ; #Delta(#phi) = (#phi_{GEN}-#phi_{TRACKING})/#phi_{GEN}; Events ",  100, -0.004, 0.004);
    auto pt_resolution = new TH1D("pt_resolution", "p_{T} resolution ; #Delta(p_{T}) = (pT_{GEN}-pT_{TRACKING})/pT_{GEN}; Events ",  100, -0.1, 0.1);
    auto eta_resolution_conv = new TH1D("eta_resolution_conv", "#eta resolution ; #delta(#eta) = #eta_{GEN}-#eta_{TRACKING}; Events ",  100, -0.004, 0.004);
    auto phi_resolution_conv = new TH1D("phi_resolution_conv", "#phi resolution ; #delta(#phi) = #phi_{GEN}-#phi_{TRACKING}; Events ",  100, -0.004, 0.004);
    auto pt_resolution_conv = new TH1D("pt_resolution_conv", "p_{T} resolution ; #delta(p_{T}) = pT_{GEN}-pT_{TRACKING}; Events ",  100, -0.2, 0.2);
    Double_t bins[] = {4.5,5.0,5.5,6.0,6.5,7.0,7.5,8.0,8.5,9.0,9.5,10.0,10.5,11.0,11.5,12.0,12.5,13.0,13.5,14.0,14.5,15.0,15.5,16.0,16.5,17.0,17.5,18.0,18.5,19.0,19.5,20.0};
    Int_t  binnum = sizeof(bins)/sizeof(Double_t) - 1;
    
    for (Int_t i=0;i<n_entries;i++) {
        mu->GetEntry(i);
        Delta_pT = (genpt-trkpt)/genpt ;
        Delta_eta = (geneta-trketa)/geneta ;
        Delta_phi = (genphi-trkphi)/genphi ;
        hresovspt->Fill(genpt, Delta_pT);
        hresoetavspt->Fill(genpt, Delta_eta);
        hresophivspt->Fill(genpt, Delta_phi);
        eta_resolution->Fill((geneta-trketa)/geneta);
        phi_resolution->Fill((genphi-trkphi)/genphi);
        pt_resolution->Fill((genpt-trkpt)/genpt);
        
        eta_resolution_conv->Fill((geneta-trketa));
        phi_resolution_conv->Fill((genphi-trkphi));
        pt_resolution_conv->Fill((genpt-trkpt));
       
        
        
        for (int j = 0 ; j < nbins; j++)
        {      if (genpt<3.5)continue;
                   if (genpt > ((20.0/nbins)*j) && genpt < ((20.0/nbins)*(j+1)) )
                              {
                                           resolution_bin[j]->Fill((genpt-trkpt)/genpt);
                                           

        }}
        
        
        
    }
    
    for (int iCand=0; iCand<n_entries; ++iCand) {
      mu->GetEntry(iCand);
       
      pt->setVal(genpt + pt_resolution_conv->GetRandom());
      eta->setVal(geneta + eta_resolution_conv->GetRandom());
      phi->setVal(genphi + phi_resolution_conv->GetRandom());
      gendata->add(vars);
    }
    
    
    for (int iCand=0; iCand<n_entries; ++iCand) {
      mu->GetEntry(iCand);
      
      pt->setVal(trkpt);
      eta->setVal(trketa);
      phi->setVal(trkphi);
      trackingdata->add(vars);
    }
    double avgEff = trackingdata->sumEntries()/gendata->sumEntries();
    cout<<"Average efficiency = "<<avgEff<<endl;
    
    TH3D* denHist = (TH3D*)gendata->createHistogram( "denHist", *pt,   Binning(xbins,2.0,20.) , YVar(*eta,Binning(ybins,-2.4,2.4)), ZVar(*phi,Binning(zbins,-TMath::Pi(),TMath::Pi())) );
    TH3D* numHist = (TH3D*)trackingdata->createHistogram("numHist", *pt,  Binning(xbins,2.0,20.0) ,   YVar(*eta,Binning(ybins,-2.4,2.4)),   ZVar(*phi,Binning(zbins,-TMath::Pi(),TMath::Pi())) );
    
    auto c1 = new TCanvas("c1", "c1", 0, 0, 1200, 400);
    TH3D *hdivideIII = (TH3D*)numHist->Clone("hdivideIII");
    hdivideIII->Sumw2();
    hdivideIII->Divide(denHist);
    auto proj2d1 =  hdivideIII->Project3D("xy");
    auto proj2d2 =  hdivideIII->Project3D("xz");
    auto proj2d3 =  hdivideIII->Project3D("yz");
    proj2d1->SetTitle("Efficiency p_{T}/#eta projection ");
    proj2d2->SetTitle("Efficiency p_{T}/#phi projection");
    proj2d3->SetTitle("Efficiency #eta/#phi projection");
    gStyle->SetPalette(kBird);
    c1->Divide(3,1);
    c1->cd(1); proj2d1->GetXaxis()->SetTitleOffset(1.4);proj2d1->GetYaxis()->SetTitleOffset(2);proj2d1->SetMinimum(0.0);proj2d1->Draw(" COLZ");
    c1->cd(2);proj2d2->GetXaxis()->SetTitleOffset(1.4);proj2d2->GetYaxis()->SetTitleOffset(2);proj2d2->SetMinimum(0.0);proj2d2->Draw("COLZ");
    c1->cd(3);proj2d3->GetXaxis()->SetTitleOffset(1.4);proj2d3->GetYaxis()->SetTitleOffset(2);proj2d3->SetMinimum(0.0);proj2d3->Draw("COLZ");
    
    TCanvas *textmy = new TCanvas();
    proj2d1->GetXaxis()->SetTitleOffset(1.4);
    proj2d1->GetYaxis()->SetTitleOffset(2);
    proj2d1->SetMinimum(0.0);
    proj2d1->Draw("TEXTE COLZ");
    
    
    
   /* auto numprojection = numHist->Project3D("xy");
    auto denoprojection = denHist->Project3D("xy");
    
    
    TH2F h2_rec("h2_rec","",xbins,2.0,20.0,ybins,-2.4,2.4);
      h2_rec.SetMinimum(0.);//Y axis minimum
      h2_rec.SetTitleOffset(2,"XY");
      h2_rec.SetXTitle("p_{T} (GeV)");
      h2_rec.SetYTitle("#eta (a.u.)");
      for (int i = 1; i <= xbins; i++) {
        for (int j = 1; j <= ybins; j++) {
          
          if (denoprojection->GetBinContent(i,j) == 0 || numprojection->GetBinContent(i,j) == 0) {
            printf("WARNING: Efficiency(%d,%d)=0, set error to be 0.\n",i,j);
            h2_rec.SetBinContent(i,j,0.);
            h2_rec.SetBinError(i,j,0.);
          }else{
            h2_rec.SetBinContent(i,j,numprojection->GetBinContent(i,j)/denoprojection->GetBinContent(i,j));//reco efficiency= h2_nreco/h2_nacc
            h2_rec.SetBinError(i,j,sqrt(h2_rec.GetBinContent(i,j)*(1-h2_rec.GetBinContent(i,j))/denoprojection->GetBinContent(i,j)));
            //printf("INFO: Efficiency(%d,%d)=%f +- %f.\n",i,j,numprojection->GetBinContent(i,j),denoprojection->GetBinError(i,j));
          }

        }
      }
    TCanvas* mapproj = new TCanvas();
    //gStyle->SetOptStat("nemr");
   proj2d1->GetXaxis()->SetTitleOffset(1.4);
    proj2d1->GetYaxis()->SetTitleOffset(2);
    proj2d1->SetMinimum(0.0);
    proj2d1->DrawNormalized("TEXT COLZ");
    //h2_rec.SetStats(1);
    //h2_rec.SetMarkerColor(kRed);
   // h2_rec.SetBarOffset(-0.2);
    gStyle->SetOptStat("nemr");
    h2_rec.SetStats(1);
    h2_rec.DrawNormalized("TEXTE COLZ");
    */
    
    
    TCanvas *c4 = new TCanvas();
    eta_resolution->Draw();
    TCanvas *c2 = new TCanvas();
    phi_resolution->Draw();
    TCanvas *c3 = new TCanvas();
    pt_resolution->Draw();
    
    
    for(int z = 0; z<nbins; z++)
          {
                  
                  rmsreso[z]  = resolution_bin[z]->GetRMS();
                  rmsresoErr[z]  = resolution_bin[z]->GetRMSError();
                  genpt_bins[z]= (20.0/nbins) + (20.0/nbins)*z;
                  genpt_binsErr[z] = 0;
                 
         }
    
    
            TCanvas *ce= new TCanvas("ce", "ce",0,0,800,600);
            TGraphErrors* gr_resoct = new TGraphErrors(nbins, genpt_bins,rmsreso, genpt_binsErr, rmsresoErr);
            gr_resoct->Draw("AC");
            TCanvas *c5 = new TCanvas();
            hresovspt->Draw("COLZ");
    TCanvas *c6 = new TCanvas();
    hresoetavspt->Draw("COLZ");
    TCanvas *c7 = new TCanvas();
    hresophivspt->Draw("COLZ");
    
    
    
    
    
    
    // Efficiency as function of  pt
    TH1F* h_pt_denom = (TH1F*) fIn1->Get("eff/h_pt_probe_all");
    TH1F* h_pt_num = (TH1F*) fIn1->Get("eff/h_pt_probe_pass");
    TCanvas* c_pt = new TCanvas("c_pt","c_pt");
    //c_pt->SetGrid(1,1);
    c_pt->cd();
    TH2F* h_pt_axis = new TH2F("h_pt_axis",";p_{T} [GeV];Efficiency of HLT_HIUPC_SingleMu0_NotMBHF2AND",100,0,20,20,0,1.2);
    h_pt_axis->GetYaxis()->SetTitleOffset(0.98);
    h_pt_axis->Draw();
    
    TEfficiency* h_pt_eff = new TEfficiency(*h_pt_num, *h_pt_denom);
    h_pt_eff->SetLineColor(kRed);
    h_pt_eff->SetMarkerColor(kRed);
    h_pt_eff->Draw("pe same");
    
    
    // Efficiency as function of  eta
    
    TH1F* h_eta_denom = (TH1F*) fIn1->Get("eff/h_eta_probe_all");
    TH1F* h_eta_num = (TH1F*) fIn1->Get("eff/h_eta_probe_pass");
    //for( unsigned ibin=1; ibin<h_eta_denom->GetNbinsX(); ++ibin )
    //std::cout << ibin << " pass/total: " << h_eta_denom->GetBinContent(ibin)<< std::endl;
    
    TCanvas* c_eta = new TCanvas("c_eta","c_eta");
    //c_eta->SetGrid(1,1);
    c_eta->cd();

    TH2F* h_eta_axis = new TH2F("h_eta_axis",";#eta;Efficiency of HLT_HIUPC_SingleMu0_NotMBHF2AND",100,-2.4,2.4,100,0,2);
    h_eta_axis->GetYaxis()->SetTitleOffset(0.98);
    h_eta_axis->Draw();
    
    TEfficiency* h_eta_eff = new TEfficiency(*h_eta_num, *h_eta_denom);
    h_eta_eff->SetLineColor(kRed);
    h_eta_eff->SetMarkerColor(kRed);
    
    h_eta_eff->Draw("pe same");

    // Efficiency as function of  phi
    
    TH1F* h_phi_denom = (TH1F*) fIn1->Get("eff/h_phi_probe_all");
    TH1F* h_phi_num = (TH1F*) fIn1->Get("eff/h_phi_probe_pass");
    
    TCanvas* c_phi = new TCanvas("c_phi","c_phi");
    //c_phi->SetGrid(1,1);
    c_phi->cd();

    TH2F* h_phi_axis = new TH2F("h_phi_axis",";#phi;Efficiency of HLT_HIUPC_SingleMu0_NotMBHF2AND",100,-TMath::Pi(),TMath::Pi(),20,0,1);
    h_phi_axis->GetYaxis()->SetTitleOffset(0.98);
    h_phi_axis->Draw();
    
    TEfficiency* h_phi_eff = new TEfficiency(*h_phi_num, *h_phi_denom);
    h_phi_eff->SetLineColor(kRed);
    h_phi_eff->SetMarkerColor(kRed);
    
    h_phi_eff->Draw("pe same");
    
    
    
    /*
     for( unsigned ibin=1; ibin<h_ptpass->GetNbinsX(); ++ibin )
     std::cout << ibin << " pass/total: " << h_ptpass->GetBinContent(ibin) <<"/"<< h_ptall->GetBinContent(ibin) << std::endl;
    h_pt_eff->SetTotalHistogram(*h_ptall,"f");
    h_pt_eff->SetPassedHistogram(*h_ptpass, "f");
     
     TFile *f = TFile::Open(infilename.c_str());
       f->cd();
       TH2F *heff = (TH2F *)f->Get(histname.c_str());

       int nbinx = heff->GetNbinsX();
       int nbiny = heff->GetNbinsY();

       float binlowedgex = -999.;
       float binhighedgex = -999.;
       float binlowedgey = -999.;
       float binhighedgey = -999.;
       float bincontent = -999.;
       float binerror = -999.;
       
       for(int j = 1; j < nbinx + 1;j++)
     {
       binlowedgex = heff->GetXaxis()->GetBinLowEdge(j);
       binhighedgex = heff->GetXaxis()->GetBinUpEdge(j);

       for(int k = 1;k < nbiny + 1;k++)
         {
           binlowedgey = heff->GetYaxis()->GetBinLowEdge(k);
               binhighedgey = heff->GetYaxis()->GetBinUpEdge(k);

           bincontent = heff->GetBinContent(j,k);
           binerror = heff->GetBinError(j,k);

           pl.push_back(binlowedgex);
           pl.push_back(binhighedgex);
               pl.push_back(binlowedgey);
               pl.push_back(binhighedgey);

           cout << " Inserting " << bincontent << " in position " << number
            << " (" << binlowedgex << " < " << inputBinningVariables[0] << " < " << binhighedgex << ", "
            << binlowedgey << " < " << inputBinningVariables[1] << " < " << binhighedgey << ")" << endl;
           pl.push_back(bincontent);
           number++;
           cout << " Inserting " << binerror << " in position " << number
            << " (" << binlowedgex << " < " << inputBinningVariables[0] << " < " << binhighedgex << ", "
                    << binlowedgey << " < " << inputBinningVariables[1] << " < " << binhighedgey << ")" << endl;
           pl.push_back(binerror);
           number++;
         }
     }

     
   */
    
}
