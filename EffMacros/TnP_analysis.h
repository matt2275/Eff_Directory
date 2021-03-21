//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Nov  5 10:26:25 2020 by ROOT version 6.18/04
// from TTree EventTree/Event data
// found on file: Inclusive_Jpsi.root
//////////////////////////////////////////////////////////

#ifndef TnP_analysis_h
#define TnP_analysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"

class TnP_analysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Int_t           pvNTracks;
   Int_t           good_vertices;
   Int_t           nPV;
   Double_t        genWeight;
   vector<string>  *triggerPath;
   vector<bool>    *triggerDecision;
   Int_t           nMu;
   vector<double>  *mu_pt;
   vector<double>  *mu_eta;
   vector<double>  *mu_phi;
   vector<double>  *mu_energy;
   vector<int>     *mu_charge;
   vector<int>     *mu_type;
   vector<double>  *mu_d0;
   vector<double>  *mu_dz;
   vector<double>  *mu_SIP;
   vector<double>  *mu_Chi2NDF;
   vector<double>  *mu_InnerD0;
   vector<double>  *mu_InnerDz;
   vector<int>     *mu_TrkLayers;
   vector<int>     *mu_PixelLayers;
   vector<int>     *mu_PixelHits;
   vector<int>     *mu_MuonHits;
   vector<int>     *mu_Stations;
   vector<int>     *mu_Matches;
   vector<int>     *mu_TrkQuality;
   vector<double>  *mu_IsoTrk;
   vector<double>  *mu_PFChIso;
   vector<double>  *mu_PFPhoIso;
   vector<double>  *mu_PFNeuIso;
   vector<double>  *mu_PFPUIso;
   vector<double>  *mu_PFCHIso03;
   vector<double>  *mu_PFPhoIso03;
   vector<double>  *mu_PFNeuIso03;
   vector<double>  *mu_PFPUIso03;
   vector<double>  *mu_InnervalidFraction;
   vector<double>  *mu_segmentCompatibility;
   vector<double>  *mu_chi2LocalPosition;
   vector<double>  *mu_trkKink;
   vector<double>  *mu_BestTrkPtError;
   vector<double>  *mu_BestTrkPt;
   vector<int>     *mu_BestTrkType;
   vector<int>     *mu_CutBasedIdLoose;
   vector<int>     *mu_CutBasedIdMedium;
   vector<int>     *mu_CutBasedIdTight;
   vector<int>     *mu_CutBasedIdMediumPrompt;
   vector<int>     *mu_CutBasedIdGlobalHighPt;
   vector<int>     *mu_CutBasedIdTrkHighPt;
   vector<int>     *mu_PFIsoVeryLoose;
   vector<int>     *mu_PFIsoLoose;
   vector<int>     *mu_PFIsoMedium;
   vector<int>     *mu_PFIsoTight;
   vector<int>     *mu_PFIsoVeryTight;
   vector<int>     *mu_PFIsoVeryVeryTight;
   vector<int>     *mu_TrkIsoLoose;
   vector<int>     *mu_TrkIsoTight;
   vector<int>     *mu_SoftCutBasedId;
   vector<int>     *mu_MvaLoose;
   vector<int>     *mu_MvaMedium;
   vector<int>     *mu_MvaTight;
   vector<int>     *mu_MiniIsoLoose;
   vector<int>     *mu_MiniIsoMedium;
   vector<int>     *mu_MiniIsoTight;
   vector<int>     *mu_MiniIsoVeryTight;
   vector<int>     *mu_TriggerIdLoose;
   vector<int>     *mu_InTimeMuon;
   vector<int>     *mu_MultiIsoLoose;
   vector<int>     *mu_MultiIsoMedium;
   vector<double>  *genMuon_pt;
   vector<double>  *genMuon_eta;
   vector<double>  *genMuon_phi;
   vector<double>  *genMuon_energy;
   vector<bool>    *passFilter_trigOpen;
   vector<bool>    *passFilter_trigNotOpen;
   Int_t           hiBin;
   vector<int>     *hiNpix;
   vector<int>     *hiNpixelTracks;
   vector<int>     *hiNtracks;
   vector<int>     *hiNtracksPtCut;
   vector<int>     *hiNtracksEtaCut;
   vector<int>     *hiNtracksEtaPtCut;
   vector<int>     *hiNpixPlus;
   vector<int>     *hiNpixMinus;
   vector<int>     *hiNpixelTracksPlus;
   vector<int>     *hiNpixelTracksMinus;
   vector<double>  *hiHF;
   vector<double>  *hiHFplus;
   vector<double>  *hiHFminus;
   vector<double>  *hiHFplusEta4;
   vector<double>  *hiHFminusEta4;
   vector<double>  *hiHFhit;
   vector<double>  *hiHFhitPlus;
   vector<double>  *hiHFhitMinus;
   vector<double>  *hiHFECut;
   vector<double>  *hiHFECutPlus;
   vector<double>  *hiEB;
   vector<double>  *hiET;
   vector<double>  *hiEE;
   vector<double>  *hiEEplus;
   vector<double>  *hiEEminus;
   vector<double>  *hiZDC;
   vector<double>  *hiZDCplus;
   vector<double>  *hiZDCminus;
   vector<double>  *BSx;
   vector<double>  *BSy;
   vector<double>  *BSz;
   vector<double>  *BSdx;
   vector<double>  *BSdy;
   vector<double>  *BSdz;
   vector<double>  *BSdxdz;
   vector<double>  *BSsigmaZ;
   vector<double>  *BSdsigmaZ;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_pvNTracks;   //!
   TBranch        *b_good_vertices;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_triggerPath;   //!
   TBranch        *b_triggerDecision;   //!
   TBranch        *b_nMu;   //!
   TBranch        *b_mu_pt;   //!
   TBranch        *b_mu_eta;   //!
   TBranch        *b_mu_phi;   //!
   TBranch        *b_mu_energy;   //!
   TBranch        *b_mu_charge;   //!
   TBranch        *b_mu_type;   //!
   TBranch        *b_mu_d0;   //!
   TBranch        *b_mu_dz;   //!
   TBranch        *b_mu_SIP;   //!
   TBranch        *b_mu_Chi2NDF;   //!
   TBranch        *b_mu_InnerD0;   //!
   TBranch        *b_mu_InnerDz;   //!
   TBranch        *b_mu_TrkLayers;   //!
   TBranch        *b_mu_PixelLayers;   //!
   TBranch        *b_mu_PixelHits;   //!
   TBranch        *b_mu_MuonHits;   //!
   TBranch        *b_mu_Stations;   //!
   TBranch        *b_mu_Matches;   //!
   TBranch        *b_mu_TrkQuality;   //!
   TBranch        *b_mu_IsoTrk;   //!
   TBranch        *b_mu_PFChIso;   //!
   TBranch        *b_mu_PFPhoIso;   //!
   TBranch        *b_mu_PFNeuIso;   //!
   TBranch        *b_mu_PFPUIso;   //!
   TBranch        *b_mu_PFCHIso03;   //!
   TBranch        *b_mu_PFPhoIso03;   //!
   TBranch        *b_mu_PFNeuIso03;   //!
   TBranch        *b_mu_PFPUIso03;   //!
   TBranch        *b_mu_InnervalidFraction;   //!
   TBranch        *b_mu_segmentCompatibility;   //!
   TBranch        *b_mu_chi2LocalPosition;   //!
   TBranch        *b_mu_trkKink;   //!
   TBranch        *b_mu_BestTrkPtError;   //!
   TBranch        *b_mu_BestTrkPt;   //!
   TBranch        *b_mu_BestTrkType;   //!
   TBranch        *b_mu_CutBasedIdLoose;   //!
   TBranch        *b_mu_CutBasedIdMedium;   //!
   TBranch        *b_mu_CutBasedIdTight;   //!
   TBranch        *b_mu_CutBasedIdMediumPrompt;   //!
   TBranch        *b_mu_CutBasedIdGlobalHighPt;   //!
   TBranch        *b_mu_CutBasedIdTrkHighPt;   //!
   TBranch        *b_mu_PFIsoVeryLoose;   //!
   TBranch        *b_mu_PFIsoLoose;   //!
   TBranch        *b_mu_PFIsoMedium;   //!
   TBranch        *b_mu_PFIsoTight;   //!
   TBranch        *b_mu_PFIsoVeryTight;   //!
   TBranch        *b_mu_PFIsoVeryVeryTight;   //!
   TBranch        *b_mu_TrkIsoLoose;   //!
   TBranch        *b_mu_TrkIsoTight;   //!
   TBranch        *b_mu_SoftCutBasedId;   //!
   TBranch        *b_mu_MvaLoose;   //!
   TBranch        *b_mu_MvaMedium;   //!
   TBranch        *b_mu_MvaTight;   //!
   TBranch        *b_mu_MiniIsoLoose;   //!
   TBranch        *b_mu_MiniIsoMedium;   //!
   TBranch        *b_mu_MiniIsoTight;   //!
   TBranch        *b_mu_MiniIsoVeryTight;   //!
   TBranch        *b_mu_TriggerIdLoose;   //!
   TBranch        *b_mu_InTimeMuon;   //!
   TBranch        *b_mu_MultiIsoLoose;   //!
   TBranch        *b_mu_MultiIsoMedium;   //!
   TBranch        *b_genMuon_pt;   //!
   TBranch        *b_genMuon_eta;   //!
   TBranch        *b_genMuon_phi;   //!
   TBranch        *b_genMuon_energy;   //!
   TBranch        *b_passFilter_trigOpen;   //!
   TBranch        *b_passFilter_trigNotOpen;   //!
   TBranch        *b_hiBin;   //!
   TBranch        *b_hiNpix;   //!
   TBranch        *b_hiNpixelTracks;   //!
   TBranch        *b_hiNtracks;   //!
   TBranch        *b_hiNtracksPtCut;   //!
   TBranch        *b_hiNtracksEtaCut;   //!
   TBranch        *b_hiNtracksEtaPtCut;   //!
   TBranch        *b_hiNpixPlus;   //!
   TBranch        *b_hiNpixMinus;   //!
   TBranch        *b_hiNpixelTracksPlus;   //!
   TBranch        *b_hiNpixelTracksMinus;   //!
   TBranch        *b_hiHF;   //!
   TBranch        *b_hiHFplus;   //!
   TBranch        *b_hiHFminus;   //!
   TBranch        *b_hiHFplusEta4;   //!
   TBranch        *b_hiHFminusEta4;   //!
   TBranch        *b_hiHFhit;   //!
   TBranch        *b_hiHFhitPlus;   //!
   TBranch        *b_hiHFhitMinus;   //!
   TBranch        *b_hiHFECut;   //!
   TBranch        *b_hiHFECutPlus;   //!
   TBranch        *b_hiEB;   //!
   TBranch        *b_hiET;   //!
   TBranch        *b_hiEE;   //!
   TBranch        *b_hiEEplus;   //!
   TBranch        *b_hiEEminus;   //!
   TBranch        *b_hiZDC;   //!
   TBranch        *b_hiZDCplus;   //!
   TBranch        *b_hiZDCminus;   //!
   TBranch        *b_BSx;   //!
   TBranch        *b_BSy;   //!
   TBranch        *b_BSz;   //!
   TBranch        *b_BSdx;   //!
   TBranch        *b_BSdy;   //!
   TBranch        *b_BSdz;   //!
   TBranch        *b_BSdxdz;   //!
   TBranch        *b_BSsigmaZ;   //!
   TBranch        *b_BSdsigmaZ;   //!

   TnP_analysis(TTree *tree=0);
   virtual ~TnP_analysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TString output);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   bool    GGMM_Muon_Def(int i, double pt);
};

#endif

#ifdef TnP_analysis_cxx
TnP_analysis::TnP_analysis(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("ggtomumu_continuum.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("ggtomumu_continuum.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("ggtomumu_continuum.root:/eff");
      dir->GetObject("EventTree",tree);

   }
   Init(tree);
}

TnP_analysis::~TnP_analysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t TnP_analysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t TnP_analysis::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void TnP_analysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   triggerPath = 0;
   triggerDecision = 0;
   mu_pt = 0;
   mu_eta = 0;
   mu_phi = 0;
   mu_energy = 0;
   mu_charge = 0;
   mu_type = 0;
   mu_d0 = 0;
   mu_dz = 0;
   mu_SIP = 0;
   mu_Chi2NDF = 0;
   mu_InnerD0 = 0;
   mu_InnerDz = 0;
   mu_TrkLayers = 0;
   mu_PixelLayers = 0;
   mu_PixelHits = 0;
   mu_MuonHits = 0;
   mu_Stations = 0;
   mu_Matches = 0;
   mu_TrkQuality = 0;
   mu_IsoTrk = 0;
   mu_PFChIso = 0;
   mu_PFPhoIso = 0;
   mu_PFNeuIso = 0;
   mu_PFPUIso = 0;
   mu_PFCHIso03 = 0;
   mu_PFPhoIso03 = 0;
   mu_PFNeuIso03 = 0;
   mu_PFPUIso03 = 0;
   mu_InnervalidFraction = 0;
   mu_segmentCompatibility = 0;
   mu_chi2LocalPosition = 0;
   mu_trkKink = 0;
   mu_BestTrkPtError = 0;
   mu_BestTrkPt = 0;
   mu_BestTrkType = 0;
   mu_CutBasedIdLoose = 0;
   mu_CutBasedIdMedium = 0;
   mu_CutBasedIdTight = 0;
   mu_CutBasedIdMediumPrompt = 0;
   mu_CutBasedIdGlobalHighPt = 0;
   mu_CutBasedIdTrkHighPt = 0;
   mu_PFIsoVeryLoose = 0;
   mu_PFIsoLoose = 0;
   mu_PFIsoMedium = 0;
   mu_PFIsoTight = 0;
   mu_PFIsoVeryTight = 0;
   mu_PFIsoVeryVeryTight = 0;
   mu_TrkIsoLoose = 0;
   mu_TrkIsoTight = 0;
   mu_SoftCutBasedId = 0;
   mu_MvaLoose = 0;
   mu_MvaMedium = 0;
   mu_MvaTight = 0;
   mu_MiniIsoLoose = 0;
   mu_MiniIsoMedium = 0;
   mu_MiniIsoTight = 0;
   mu_MiniIsoVeryTight = 0;
   mu_TriggerIdLoose = 0;
   mu_InTimeMuon = 0;
   mu_MultiIsoLoose = 0;
   mu_MultiIsoMedium = 0;
   genMuon_pt = 0;
   genMuon_eta = 0;
   genMuon_phi = 0;
   genMuon_energy = 0;
   passFilter_trigOpen = 0;
   passFilter_trigNotOpen = 0;
   hiNpix = 0;
   hiNpixelTracks = 0;
   hiNtracks = 0;
   hiNtracksPtCut = 0;
   hiNtracksEtaCut = 0;
   hiNtracksEtaPtCut = 0;
   hiNpixPlus = 0;
   hiNpixMinus = 0;
   hiNpixelTracksPlus = 0;
   hiNpixelTracksMinus = 0;
   hiHF = 0;
   hiHFplus = 0;
   hiHFminus = 0;
   hiHFplusEta4 = 0;
   hiHFminusEta4 = 0;
   hiHFhit = 0;
   hiHFhitPlus = 0;
   hiHFhitMinus = 0;
   hiHFECut = 0;
   hiHFECutPlus = 0;
   hiEB = 0;
   hiET = 0;
   hiEE = 0;
   hiEEplus = 0;
   hiEEminus = 0;
   hiZDC = 0;
   hiZDCplus = 0;
   hiZDCminus = 0;
   BSx = 0;
   BSy = 0;
   BSz = 0;
   BSdx = 0;
   BSdy = 0;
   BSdz = 0;
   BSdxdz = 0;
   BSsigmaZ = 0;
   BSdsigmaZ = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("pvNTracks", &pvNTracks, &b_pvNTracks);
   fChain->SetBranchAddress("good_vertices", &good_vertices, &b_good_vertices);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("triggerPath", &triggerPath, &b_triggerPath);
   fChain->SetBranchAddress("triggerDecision", &triggerDecision, &b_triggerDecision);
   fChain->SetBranchAddress("nMu", &nMu, &b_nMu);
   fChain->SetBranchAddress("mu_pt", &mu_pt, &b_mu_pt);
   fChain->SetBranchAddress("mu_eta", &mu_eta, &b_mu_eta);
   fChain->SetBranchAddress("mu_phi", &mu_phi, &b_mu_phi);
   fChain->SetBranchAddress("mu_energy", &mu_energy, &b_mu_energy);
   fChain->SetBranchAddress("mu_charge", &mu_charge, &b_mu_charge);
   fChain->SetBranchAddress("mu_type", &mu_type, &b_mu_type);
   fChain->SetBranchAddress("mu_d0", &mu_d0, &b_mu_d0);
   fChain->SetBranchAddress("mu_dz", &mu_dz, &b_mu_dz);
   fChain->SetBranchAddress("mu_SIP", &mu_SIP, &b_mu_SIP);
   fChain->SetBranchAddress("mu_Chi2NDF", &mu_Chi2NDF, &b_mu_Chi2NDF);
   fChain->SetBranchAddress("mu_InnerD0", &mu_InnerD0, &b_mu_InnerD0);
   fChain->SetBranchAddress("mu_InnerDz", &mu_InnerDz, &b_mu_InnerDz);
   fChain->SetBranchAddress("mu_TrkLayers", &mu_TrkLayers, &b_mu_TrkLayers);
   fChain->SetBranchAddress("mu_PixelLayers", &mu_PixelLayers, &b_mu_PixelLayers);
   fChain->SetBranchAddress("mu_PixelHits", &mu_PixelHits, &b_mu_PixelHits);
   fChain->SetBranchAddress("mu_MuonHits", &mu_MuonHits, &b_mu_MuonHits);
   fChain->SetBranchAddress("mu_Stations", &mu_Stations, &b_mu_Stations);
   fChain->SetBranchAddress("mu_Matches", &mu_Matches, &b_mu_Matches);
   fChain->SetBranchAddress("mu_TrkQuality", &mu_TrkQuality, &b_mu_TrkQuality);
   fChain->SetBranchAddress("mu_IsoTrk", &mu_IsoTrk, &b_mu_IsoTrk);
   fChain->SetBranchAddress("mu_PFChIso", &mu_PFChIso, &b_mu_PFChIso);
   fChain->SetBranchAddress("mu_PFPhoIso", &mu_PFPhoIso, &b_mu_PFPhoIso);
   fChain->SetBranchAddress("mu_PFNeuIso", &mu_PFNeuIso, &b_mu_PFNeuIso);
   fChain->SetBranchAddress("mu_PFPUIso", &mu_PFPUIso, &b_mu_PFPUIso);
   fChain->SetBranchAddress("mu_PFCHIso03", &mu_PFCHIso03, &b_mu_PFCHIso03);
   fChain->SetBranchAddress("mu_PFPhoIso03", &mu_PFPhoIso03, &b_mu_PFPhoIso03);
   fChain->SetBranchAddress("mu_PFNeuIso03", &mu_PFNeuIso03, &b_mu_PFNeuIso03);
   fChain->SetBranchAddress("mu_PFPUIso03", &mu_PFPUIso03, &b_mu_PFPUIso03);
   fChain->SetBranchAddress("mu_InnervalidFraction", &mu_InnervalidFraction, &b_mu_InnervalidFraction);
   fChain->SetBranchAddress("mu_segmentCompatibility", &mu_segmentCompatibility, &b_mu_segmentCompatibility);
   fChain->SetBranchAddress("mu_chi2LocalPosition", &mu_chi2LocalPosition, &b_mu_chi2LocalPosition);
   fChain->SetBranchAddress("mu_trkKink", &mu_trkKink, &b_mu_trkKink);
   fChain->SetBranchAddress("mu_BestTrkPtError", &mu_BestTrkPtError, &b_mu_BestTrkPtError);
   fChain->SetBranchAddress("mu_BestTrkPt", &mu_BestTrkPt, &b_mu_BestTrkPt);
   fChain->SetBranchAddress("mu_BestTrkType", &mu_BestTrkType, &b_mu_BestTrkType);
   fChain->SetBranchAddress("mu_CutBasedIdLoose", &mu_CutBasedIdLoose, &b_mu_CutBasedIdLoose);
   fChain->SetBranchAddress("mu_CutBasedIdMedium", &mu_CutBasedIdMedium, &b_mu_CutBasedIdMedium);
   fChain->SetBranchAddress("mu_CutBasedIdTight", &mu_CutBasedIdTight, &b_mu_CutBasedIdTight);
   fChain->SetBranchAddress("mu_CutBasedIdMediumPrompt", &mu_CutBasedIdMediumPrompt, &b_mu_CutBasedIdMediumPrompt);
   fChain->SetBranchAddress("mu_CutBasedIdGlobalHighPt", &mu_CutBasedIdGlobalHighPt, &b_mu_CutBasedIdGlobalHighPt);
   fChain->SetBranchAddress("mu_CutBasedIdTrkHighPt", &mu_CutBasedIdTrkHighPt, &b_mu_CutBasedIdTrkHighPt);
   fChain->SetBranchAddress("mu_PFIsoVeryLoose", &mu_PFIsoVeryLoose, &b_mu_PFIsoVeryLoose);
   fChain->SetBranchAddress("mu_PFIsoLoose", &mu_PFIsoLoose, &b_mu_PFIsoLoose);
   fChain->SetBranchAddress("mu_PFIsoMedium", &mu_PFIsoMedium, &b_mu_PFIsoMedium);
   fChain->SetBranchAddress("mu_PFIsoTight", &mu_PFIsoTight, &b_mu_PFIsoTight);
   fChain->SetBranchAddress("mu_PFIsoVeryTight", &mu_PFIsoVeryTight, &b_mu_PFIsoVeryTight);
   fChain->SetBranchAddress("mu_PFIsoVeryVeryTight", &mu_PFIsoVeryVeryTight, &b_mu_PFIsoVeryVeryTight);
   fChain->SetBranchAddress("mu_TrkIsoLoose", &mu_TrkIsoLoose, &b_mu_TrkIsoLoose);
   fChain->SetBranchAddress("mu_TrkIsoTight", &mu_TrkIsoTight, &b_mu_TrkIsoTight);
   fChain->SetBranchAddress("mu_SoftCutBasedId", &mu_SoftCutBasedId, &b_mu_SoftCutBasedId);
   fChain->SetBranchAddress("mu_MvaLoose", &mu_MvaLoose, &b_mu_MvaLoose);
   fChain->SetBranchAddress("mu_MvaMedium", &mu_MvaMedium, &b_mu_MvaMedium);
   fChain->SetBranchAddress("mu_MvaTight", &mu_MvaTight, &b_mu_MvaTight);
   fChain->SetBranchAddress("mu_MiniIsoLoose", &mu_MiniIsoLoose, &b_mu_MiniIsoLoose);
   fChain->SetBranchAddress("mu_MiniIsoMedium", &mu_MiniIsoMedium, &b_mu_MiniIsoMedium);
   fChain->SetBranchAddress("mu_MiniIsoTight", &mu_MiniIsoTight, &b_mu_MiniIsoTight);
   fChain->SetBranchAddress("mu_MiniIsoVeryTight", &mu_MiniIsoVeryTight, &b_mu_MiniIsoVeryTight);
   fChain->SetBranchAddress("mu_TriggerIdLoose", &mu_TriggerIdLoose, &b_mu_TriggerIdLoose);
   fChain->SetBranchAddress("mu_InTimeMuon", &mu_InTimeMuon, &b_mu_InTimeMuon);
   fChain->SetBranchAddress("mu_MultiIsoLoose", &mu_MultiIsoLoose, &b_mu_MultiIsoLoose);
   fChain->SetBranchAddress("mu_MultiIsoMedium", &mu_MultiIsoMedium, &b_mu_MultiIsoMedium);
   fChain->SetBranchAddress("genMuon_pt", &genMuon_pt, &b_genMuon_pt);
   fChain->SetBranchAddress("genMuon_eta", &genMuon_eta, &b_genMuon_eta);
   fChain->SetBranchAddress("genMuon_phi", &genMuon_phi, &b_genMuon_phi);
   fChain->SetBranchAddress("genMuon_energy", &genMuon_energy, &b_genMuon_energy);
   fChain->SetBranchAddress("passFilter_trigOpen", &passFilter_trigOpen, &b_passFilter_trigOpen);
   fChain->SetBranchAddress("passFilter_trigNotOpen", &passFilter_trigNotOpen, &b_passFilter_trigNotOpen);
   fChain->SetBranchAddress("hiBin", &hiBin, &b_hiBin);
   fChain->SetBranchAddress("hiNpix", &hiNpix, &b_hiNpix);
   fChain->SetBranchAddress("hiNpixelTracks", &hiNpixelTracks, &b_hiNpixelTracks);
   fChain->SetBranchAddress("hiNtracks", &hiNtracks, &b_hiNtracks);
   fChain->SetBranchAddress("hiNtracksPtCut", &hiNtracksPtCut, &b_hiNtracksPtCut);
   fChain->SetBranchAddress("hiNtracksEtaCut", &hiNtracksEtaCut, &b_hiNtracksEtaCut);
   fChain->SetBranchAddress("hiNtracksEtaPtCut", &hiNtracksEtaPtCut, &b_hiNtracksEtaPtCut);
   fChain->SetBranchAddress("hiNpixPlus", &hiNpixPlus, &b_hiNpixPlus);
   fChain->SetBranchAddress("hiNpixMinus", &hiNpixMinus, &b_hiNpixMinus);
   fChain->SetBranchAddress("hiNpixelTracksPlus", &hiNpixelTracksPlus, &b_hiNpixelTracksPlus);
   fChain->SetBranchAddress("hiNpixelTracksMinus", &hiNpixelTracksMinus, &b_hiNpixelTracksMinus);
   fChain->SetBranchAddress("hiHF", &hiHF, &b_hiHF);
   fChain->SetBranchAddress("hiHFplus", &hiHFplus, &b_hiHFplus);
   fChain->SetBranchAddress("hiHFminus", &hiHFminus, &b_hiHFminus);
   fChain->SetBranchAddress("hiHFplusEta4", &hiHFplusEta4, &b_hiHFplusEta4);
   fChain->SetBranchAddress("hiHFminusEta4", &hiHFminusEta4, &b_hiHFminusEta4);
   fChain->SetBranchAddress("hiHFhit", &hiHFhit, &b_hiHFhit);
   fChain->SetBranchAddress("hiHFhitPlus", &hiHFhitPlus, &b_hiHFhitPlus);
   fChain->SetBranchAddress("hiHFhitMinus", &hiHFhitMinus, &b_hiHFhitMinus);
   fChain->SetBranchAddress("hiHFECut", &hiHFECut, &b_hiHFECut);
   fChain->SetBranchAddress("hiHFECutPlus", &hiHFECutPlus, &b_hiHFECutPlus);
   fChain->SetBranchAddress("hiEB", &hiEB, &b_hiEB);
   fChain->SetBranchAddress("hiET", &hiET, &b_hiET);
   fChain->SetBranchAddress("hiEE", &hiEE, &b_hiEE);
   fChain->SetBranchAddress("hiEEplus", &hiEEplus, &b_hiEEplus);
   fChain->SetBranchAddress("hiEEminus", &hiEEminus, &b_hiEEminus);
   fChain->SetBranchAddress("hiZDC", &hiZDC, &b_hiZDC);
   fChain->SetBranchAddress("hiZDCplus", &hiZDCplus, &b_hiZDCplus);
   fChain->SetBranchAddress("hiZDCminus", &hiZDCminus, &b_hiZDCminus);
   fChain->SetBranchAddress("BSx", &BSx, &b_BSx);
   fChain->SetBranchAddress("BSy", &BSy, &b_BSy);
   fChain->SetBranchAddress("BSz", &BSz, &b_BSz);
   fChain->SetBranchAddress("BSdx", &BSdx, &b_BSdx);
   fChain->SetBranchAddress("BSdy", &BSdy, &b_BSdy);
   fChain->SetBranchAddress("BSdz", &BSdz, &b_BSdz);
   fChain->SetBranchAddress("BSdxdz", &BSdxdz, &b_BSdxdz);
   fChain->SetBranchAddress("BSsigmaZ", &BSsigmaZ, &b_BSsigmaZ);
   fChain->SetBranchAddress("BSdsigmaZ", &BSdsigmaZ, &b_BSdsigmaZ);
   Notify();
}

Bool_t TnP_analysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void TnP_analysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t TnP_analysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef TnP_analysis_cxx
