#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TTree.h"
#include "TH1D.h"
#include "TRandom.h"

using namespace RooFit ;
using namespace std;

void histograms(){

    TFile *fIn1 = new TFile("trktrig_eff_UPCSMuon_InclusiveJpsi_Data.root");
    TH1F* hmllA = (TH1F*) fIn1->Get("eff/h_trigmll_all");
    TH1F* hmllP = (TH1F*) fIn1->Get("eff/h_trigmll_pass");
    TFile *outf = TFile::Open("jpsi_data_histograms.root","RECREATE");
    hmllA->Write();
    hmllP->Write();

    outf->Close();

   TFile *fIn2 = new TFile("trktrig_eff_UPCSMuon_InclusiveJpsi_MC.root");
   TH1F* hmll_A = (TH1F*) fIn2->Get("eff/h_trigmll_all");
   TH1F* hmll_P = (TH1F*) fIn2->Get("eff/h_trigmll_pass");
   TFile *out_f = TFile::Open("jpsi_mc_histograms.root","RECREATE");
   hmll_A->Write();
   hmll_P->Write();

   out_f->Close();


}
