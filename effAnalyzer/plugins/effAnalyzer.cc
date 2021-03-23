// -*- C++ -*-
//
// Package:    Eff_Directory/effAnalyzer
// Class:      effAnalyzer
//
/**\class effAnalyzer effAnalyzer.cc Eff_Directory/effAnalyzer/plugins/effAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:   Muhammad Alibordi
//         Created:  Mon, 20 Apr 2020 10:46:25 GMT
//
//


// system include files
#include <memory>
// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
 #include "FWCore/Utilities/interface/InputTag.h"
 #include "DataFormats/TrackReco/interface/Track.h"
 #include "DataFormats/TrackReco/interface/TrackFwd.h"
//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<>
// This will improve performance in multithreaded jobs.
#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "FWCore/ParameterSet/interface/ParameterSetfwd.h"
#include <iostream>
#include <memory>
#include <vector>
#include <iomanip>
#include <TVector3.h>
#include <TLorentzVector.h>
#include <TProfile.h>
#include <TTree.h>
#include <TMath.h>
#include "DataFormats/PatCandidates/interface/Lepton.h"
#include "DataFormats/Candidate/interface/CompositeCandidate.h"
#include "DataFormats/TrackReco/interface/TrackBase.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/PatCandidates/interface/GenericParticle.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "MagneticField/Engine/interface/MagneticField.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "RecoVertex/VertexPrimitives/interface/TransientVertex.h"
#include "RecoVertex/KalmanVertexFit/interface/KalmanVertexFitter.h"
#include "SimTracker/Records/interface/TrackAssociatorRecord.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/Math/interface/deltaPhi.h"
#include "PhysicsTools/PatAlgos/plugins/PATJetProducer.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include <iostream>
#include <algorithm>
#include <bitset>
#include "DataFormats/HeavyIonEvent/interface/CentralityBins.h"
#include "DataFormats/HeavyIonEvent/interface/Centrality.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/StreamID.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupMixingContent.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupVertexContent.h"
#include "DataFormats/PatCandidates/interface/IsolatedTrack.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/TrackExtra.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticle.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticleFwd.h"
#include "RecoVertex/VertexTools/interface/VertexDistance3D.h"
#include "RecoVertex/VertexTools/interface/VertexDistanceXY.h"
#include "MuonAnalysis/MuonAssociators/interface/L1MuonMatcherAlgo.h"
#include "TrackingTools/Records/interface/TrackingComponentsRecord.h"
#include "TLorentzVector.h"
#include "TLorentzRotation.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/Common/interface/Association.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "FWCore/Framework/interface/TriggerReport.h"
#include "FWCore/Framework/interface/TriggerNamesService.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"   
#include "DataFormats/MuonReco/interface/MuonQuality.h" 
#include "DataFormats/PatCandidates/interface/TriggerAlgorithm.h"
#include "DataFormats/PatCandidates/interface/TriggerCondition.h"
#include "DataFormats/PatCandidates/interface/TriggerPath.h"
#include "DataFormats/PatCandidates/interface/TriggerFilter.h"
#include "DataFormats/PatCandidates/interface/TriggerObject.h"
#include "TrackingTools/PatternTools/interface/ClosestApproachInRPhi.h"
#include "CommonTools/CandUtils/interface/AddFourMomenta.h"   
using namespace edm;
    using namespace std;
    using namespace reco;
    using namespace pat;






class effAnalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit effAnalyzer(const edm::ParameterSet&);
      ~effAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

    typedef math::XYZTLorentzVectorF LorentzVector;
   

   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;
    
   void bookHists(edm::Service<TFileService>& fs, const std::string& suffix);
   void fillHists(const LorentzVector& lv, const std::string& suffix); 

      // ----------member data ---------------------------
    
    double nominalMuonMass = 0.1056583;
    double nominalJpsiMass = 3.096916;
    bool isMCstudy_;
    double JpsiMassWindow; 
    edm::InputTag muon;
    edm::EDGetTokenT<edm::View<reco::Muon>> muonTok;
    edm::InputTag primaryvertex;
    edm::EDGetTokenT<edm::View<reco::Vertex>> primaryvertexTok;
    edm::InputTag track;
    edm::EDGetTokenT<edm::View<reco::Track>> trackTok;
    edm::InputTag geninfo;
    edm::EDGetTokenT<edm::View<reco::GenParticle>> geninfoTok;
    edm::InputTag triggerresults;
    edm::EDGetTokenT<edm::TriggerResults>triggerresultsTok;
    edm::InputTag trigsummary;
    edm::EDGetTokenT<trigger::TriggerEvent>trigsummaryTok;
    edm::InputTag filtertag;
    HLTConfigProvider hltConfiguration;
    edm::InputTag offlineBS;
    edm::EDGetTokenT<reco::BeamSpot> offlineBSTok;
    edm::InputTag CentralitySrc;
    edm::EDGetTokenT<reco::Centrality> CentralityTok;
    edm::InputTag CentralityBinSrc;
    edm::EDGetTokenT<int> CentralityBinSrcTok;
    edm::InputTag genEventInfoProduct;
    edm::EDGetTokenT<GenEventInfoProduct>genEventInfoProductTok;    
      std::vector<std::string> pathsToSave_;
      std::vector<std::string> filterToMatch_;
      std::string HLTprocess_;

std::map<std::string,TH1F*> hists_1d_;
   //-------------Tree and variables -------------------
     TTree * tree_;

   //Pv vars
   Int_t pvNTracks_; 
   Int_t good_vertices_; //generated pile up
   Int_t nPV_; //number of reconsrtucted primary vertices
   
   //Trigger names and decisions 
   std::vector<bool> triggerDecision;
   std::vector<std::string> triggerPath;
   
   //Muon vars

     Int_t nMuons_;
     std::vector<double> mu_pt_;
     std::vector<double> mu_eta_;
     std::vector<double> mu_phi_;
     std::vector<double> mu_energy_;
     std::vector<int> mu_charge_;
     std::vector<int> mu_type_;
     std::vector<double> mu_d0_;
     std::vector<double> mu_dz_;
     std::vector<double> mu_SIP_;
     std::vector<double> mu_Chi2NDF_;
     std::vector<double> mu_InnerD0_;
     std::vector<double> mu_InnerDz_;
     std::vector<int>      mu_TrkLayers_;
     std::vector<int>      mu_PixelLayers_;
     std::vector<int>      mu_PixelHits_;
     std::vector<int>      mu_MuonHits_;
     std::vector<int>      mu_Stations_;
     std::vector<int>      mu_Matches_;
     std::vector<int>      mu_TrkQuality_;
     std::vector<double>    mu_IsoTrk_;
     std::vector<double>    mu_PFChIso_;
     std::vector<double>    mu_PFPhoIso_;
     std::vector<double>    mu_PFNeuIso_;
     std::vector<double>    mu_PFPUIso_;
     std::vector<double>    mu_PFChIso03_;
     std::vector<double>    mu_PFPhoIso03_;
     std::vector<double>    mu_PFNeuIso03_;
     std::vector<double>    mu_PFPUIso03_;
     std::vector<double>    mu_InnervalidFraction_;
     std::vector<double>    mu_segmentCompatibility_;
     std::vector<double>    mu_chi2LocalPosition_;
     std::vector<double>    mu_trkKink_;
     std::vector<double>    mu_BestTrkPtError_;
     std::vector<double>    mu_BestTrkPt_;
     std::vector<int>      mu_BestTrkType_;

     std::vector<int>      mu_CutBasedIdLoose_;
     std::vector<int>      mu_CutBasedIdMedium_;
     std::vector<int>      mu_CutBasedIdTight_;
     std::vector<int>      mu_CutBasedIdMediumPrompt_;
     std::vector<int>      mu_CutBasedIdGlobalHighPt_;
     std::vector<int>      mu_CutBasedIdTrkHighPt_;
     std::vector<int>      mu_PFIsoVeryLoose_;
     std::vector<int>      mu_PFIsoLoose_;
     std::vector<int>      mu_PFIsoMedium_;
     std::vector<int>      mu_PFIsoTight_;
     std::vector<int>      mu_PFIsoVeryTight_;
     std::vector<int>      mu_PFIsoVeryVeryTight_;
     std::vector<int>      mu_TrkIsoLoose_;
     std::vector<int>      mu_TrkIsoTight_;
     std::vector<int>      mu_SoftCutBasedId_;
     std::vector<int>      mu_MvaLoose_;
     std::vector<int>      mu_MvaMedium_;
     std::vector<int>      mu_MvaTight_;
     std::vector<int>      mu_MiniIsoLoose_;
     std::vector<int>      mu_MiniIsoMedium_;
     std::vector<int>      mu_MiniIsoTight_;
     std::vector<int>      mu_MiniIsoVeryTight_;
     std::vector<int>      mu_TriggerIdLoose_;
     std::vector<int>      mu_InTimeMuon_;
     std::vector<int>      mu_MultiIsoLoose_;
     std::vector<int>      mu_MultiIsoMedium_;

     std::vector<bool> passFilter_trigOpen;
     std::vector<bool> passFilter_trigNotOpen;
     
     //Gen particles
     std::vector<double> genMuon_pt;
     std::vector<double> genMuon_eta;
     std::vector<double> genMuon_phi;
     std::vector<double> genMuon_energy;
     std::vector<bool>   genMuon_fromZ;

  const MagneticField* magneticField_; 
  

  std::vector<double> BSx;
  std::vector<double> BSy;
  std::vector<double> BSz;
  std::vector<double> BSdx;
  std::vector<double> BSdy;
  std::vector<double> BSdz;
  std::vector<double> BSdxdz;
  std::vector<double> BSdydz;
  std::vector<double> BSsigmaZ;
  std::vector<double> BSdsigmaZ;
//  std::vector<double> MuonsDCA;   
 // std::vector<double> vtxProb_dimuon;
 // std::vector<double> CosAlpha; 

  //centrality information 
    int hiBin;
    std::vector<int> hiNpix;
    std::vector<int> hiNpixelTracks;
    std::vector<int> hiNtracks;
    std::vector<int> hiNtracksPtCut;
   std::vector<int> hiNtracksEtaCut;
   std::vector<int> hiNtracksEtaPtCut;
    std::vector<int> hiNpixPlus;
   std::vector<int> hiNpixMinus;
   std::vector<int> hiNpixelTracksPlus;
   std::vector<int> hiNpixelTracksMinus;
    std::vector<double> hiHF;
    std::vector<double>  hiHFplus;
    std::vector<double>  hiHFminus;
    std::vector<double>  hiHFplusEta4;
    std::vector<double>  hiHFminusEta4;
    std::vector<double>  hiHFhit;
    std::vector<double>  hiHFhitPlus;
    std::vector<double>  hiHFhitMinus;
    std::vector<double>  hiHFECut;
    std::vector<double>  hiHFECutPlus;
    std::vector<double>  hiHFECutMinus;
    std::vector<double>  hiEB;
    std::vector<double>  hiET;
    std::vector<double>  hiEE;
    std::vector<double>  hiEEplus;
    std::vector<double>  hiEEminus;
    std::vector<double>  hiZDC;
    std::vector<double>  hiZDCplus;
    std::vector<double>  hiZDCminus;
    uint32_t     run_;
    double   genWeight_;
};


effAnalyzer::effAnalyzer(const edm::ParameterSet& iConfig):
  isMCstudy_(iConfig.getParameter<bool>("isMCstudy")),
  JpsiMassWindow(iConfig.getParameter<double>("JpsiWindow")),
  muon(iConfig.getUntrackedParameter<edm::InputTag>("muon")),
  muonTok(consumes<edm::View<reco::Muon>>(muon)),
  primaryvertex(iConfig.getUntrackedParameter<edm::InputTag>("primaryvertex")),
  primaryvertexTok(consumes<edm::View<reco::Vertex>>(primaryvertex)),
  track(iConfig.getUntrackedParameter<edm::InputTag>("track")),
  trackTok(consumes<edm::View<reco::Track>>(track)),
  geninfo(iConfig.getUntrackedParameter<edm::InputTag>("geninfo")),
  geninfoTok(consumes<edm::View<reco::GenParticle>>(geninfo)),
  triggerresults(iConfig.getUntrackedParameter<edm::InputTag>("triggerresults")),
  triggerresultsTok(consumes<edm::TriggerResults>(triggerresults)),
  trigsummary(iConfig.getUntrackedParameter<edm::InputTag>("trigsummary")),
  trigsummaryTok(consumes<trigger::TriggerEvent>(trigsummary)),
  filtertag(iConfig.getUntrackedParameter<edm::InputTag>("filtertag")),
  offlineBS(iConfig.getUntrackedParameter<edm::InputTag>("offlineBS")),
  offlineBSTok(consumes<reco::BeamSpot>(offlineBS)),
  CentralitySrc(iConfig.getUntrackedParameter<edm::InputTag>("CentralitySrc")),
  CentralityTok(consumes<reco::Centrality>(CentralitySrc)),
  CentralityBinSrc(iConfig.getUntrackedParameter<edm::InputTag>("CentralityBinSrc")),
  CentralityBinSrcTok(consumes<int>(CentralityBinSrc)),
  genEventInfoProduct(iConfig.getUntrackedParameter<edm::InputTag>("genEventInfoProduct")),
  genEventInfoProductTok(consumes<GenEventInfoProduct>(genEventInfoProduct)),
  pathsToSave_(iConfig.getParameter<std::vector<std::string>>("pathsToSave")),
  filterToMatch_(iConfig.getParameter<std::vector<std::string>>("filterToMatch")),
  HLTprocess_(iConfig.getParameter<std::string>("HLTprocess"))
   

{
 
      
  edm::Service<TFileService> fs;

  tree_ = fs->make<TTree> ("EventTree", "Event data");
  tree_->Branch("run",  &run_,  "run/I"); 
  tree_->Branch("pvNTracks"    ,  &pvNTracks_ , "pvNTracks/I");
  tree_->Branch("good_vertices",  &good_vertices_, "good_vertices/I");
  tree_->Branch("nPV"        ,  &nPV_     , "nPV/I");
  tree_->Branch("genWeight"    ,  &genWeight_ , "genWeight/D");
  tree_->Branch("triggerPath" ,  &triggerPath);
  tree_->Branch("triggerDecision" ,  &triggerDecision);

  tree_->Branch("nMu", &nMuons_ , "nMu/I" );
  tree_->Branch("mu_pt",&mu_pt_);
  tree_->Branch("mu_eta",&mu_eta_);
  tree_->Branch("mu_phi",&mu_phi_);
  tree_->Branch("mu_energy",&mu_energy_);
  tree_->Branch("mu_charge",&mu_charge_);
  tree_->Branch("mu_type",&mu_type_);
  tree_->Branch("mu_d0",&mu_d0_);
  tree_->Branch("mu_dz",&mu_dz_);
  tree_->Branch("mu_SIP",&mu_SIP_);
  tree_->Branch("mu_Chi2NDF",&mu_Chi2NDF_);
  tree_->Branch("mu_InnerD0",&mu_InnerD0_);
  tree_->Branch("mu_InnerDz",&mu_InnerDz_);
  tree_->Branch("mu_TrkLayers",&mu_TrkLayers_);
  tree_->Branch("mu_PixelLayers",&mu_PixelLayers_);
  tree_->Branch("mu_PixelHits",&mu_PixelHits_);
  tree_->Branch("mu_MuonHits",&mu_MuonHits_);
  tree_->Branch("mu_Stations",&mu_Stations_);
  tree_->Branch("mu_Matches",&mu_Matches_);
  tree_->Branch("mu_TrkQuality",&mu_TrkQuality_);
  tree_->Branch("mu_IsoTrk",&mu_IsoTrk_);
  tree_->Branch("mu_PFChIso",&mu_PFChIso_);
  tree_->Branch("mu_PFPhoIso",&mu_PFPhoIso_);
  tree_->Branch("mu_PFNeuIso",&mu_PFNeuIso_);  
  tree_->Branch("mu_PFPUIso",&mu_PFPUIso_);   
  tree_->Branch("mu_PFCHIso03",&mu_PFChIso03_); 
  tree_->Branch("mu_PFPhoIso03",&mu_PFPhoIso03_);
  tree_->Branch("mu_PFNeuIso03",&mu_PFNeuIso03_);
  tree_->Branch("mu_PFPUIso03",&mu_PFPUIso03_); 
  tree_->Branch("mu_InnervalidFraction",&mu_InnervalidFraction_);   
  tree_->Branch("mu_segmentCompatibility",&mu_segmentCompatibility_);  
  tree_->Branch("mu_chi2LocalPosition",&mu_chi2LocalPosition_); 
  tree_->Branch("mu_trkKink",&mu_trkKink_);   
  tree_->Branch("mu_BestTrkPtError",&mu_BestTrkPtError_);
  tree_->Branch("mu_BestTrkPt",&mu_BestTrkPt_); 
  tree_->Branch("mu_BestTrkType",&mu_BestTrkType_);
  tree_->Branch("mu_CutBasedIdLoose",&mu_CutBasedIdLoose_);
  tree_->Branch("mu_CutBasedIdMedium",&mu_CutBasedIdMedium_);
  tree_->Branch("mu_CutBasedIdTight",&mu_CutBasedIdTight_);
  tree_->Branch("mu_CutBasedIdMediumPrompt",&mu_CutBasedIdMediumPrompt_);
  tree_->Branch("mu_CutBasedIdGlobalHighPt",&mu_CutBasedIdGlobalHighPt_);
  tree_->Branch("mu_CutBasedIdTrkHighPt",&mu_CutBasedIdTrkHighPt_);
  tree_->Branch("mu_PFIsoVeryLoose",&mu_PFIsoVeryLoose_);
  tree_->Branch("mu_PFIsoLoose",&mu_PFIsoLoose_); 
  tree_->Branch("mu_PFIsoMedium",&mu_PFIsoMedium_);
  tree_->Branch("mu_PFIsoTight",&mu_PFIsoTight_); 
  tree_->Branch("mu_PFIsoVeryTight",&mu_PFIsoVeryTight_);
  tree_->Branch("mu_PFIsoVeryVeryTight",&mu_PFIsoVeryVeryTight_);
  tree_->Branch("mu_TrkIsoLoose",&mu_TrkIsoLoose_);
  tree_->Branch("mu_TrkIsoTight",&mu_TrkIsoTight_);
  tree_->Branch("mu_SoftCutBasedId",&mu_SoftCutBasedId_);
  tree_->Branch("mu_MvaLoose",&mu_MvaLoose_);   
  tree_->Branch("mu_MvaMedium",&mu_MvaMedium_);  
  tree_->Branch("mu_MvaTight",&mu_MvaTight_);   
  tree_->Branch("mu_MiniIsoLoose",&mu_MiniIsoLoose_);
  tree_->Branch("mu_MiniIsoMedium",&mu_MiniIsoMedium_);
  tree_->Branch("mu_MiniIsoTight",&mu_MiniIsoTight_);
  tree_->Branch("mu_MiniIsoVeryTight",&mu_MiniIsoVeryTight_);
  tree_->Branch("mu_TriggerIdLoose",&mu_TriggerIdLoose_);
  tree_->Branch("mu_InTimeMuon",&mu_InTimeMuon_); 
  tree_->Branch("mu_MultiIsoLoose",&mu_MultiIsoLoose_);
  tree_->Branch("mu_MultiIsoMedium",&mu_MultiIsoMedium_);

  tree_->Branch("genMuon_pt" ,  &genMuon_pt);
  tree_->Branch("genMuon_eta" ,  &genMuon_eta);
  tree_->Branch("genMuon_phi" ,  &genMuon_phi);
  tree_->Branch("genMuon_energy" ,  &genMuon_energy);
 //tree_->Branch("genMuon_fromZ" ,  &genMuon_fromZ);


  tree_->Branch("passFilter_trigOpen" ,  &passFilter_trigOpen);
  tree_->Branch("passFilter_trigNotOpen" ,  &passFilter_trigNotOpen); 
  
  tree_->Branch("hiBin",&hiBin);
  tree_->Branch("hiNpix",&hiNpix);
tree_->Branch("hiNpixelTracks",&hiNpixelTracks);
tree_->Branch("hiNtracks",&hiNtracks);
tree_->Branch("hiNtracksPtCut",&hiNtracksPtCut);
tree_->Branch("hiNtracksEtaCut",&hiNtracksEtaCut);
tree_->Branch("hiNtracksEtaPtCut",&hiNtracksEtaPtCut);
tree_->Branch("hiNpixPlus",&hiNpixPlus);
tree_->Branch("hiNpixMinus",&hiNpixMinus);
tree_->Branch("hiNpixelTracksPlus",&hiNpixelTracksPlus);
tree_->Branch("hiNpixelTracksMinus",&hiNpixelTracksMinus);
tree_->Branch("hiHF",&hiHF);
tree_->Branch("hiHFplus",&hiHFplus);
tree_->Branch("hiHFminus",&hiHFminus);
tree_->Branch("hiHFplusEta4",&hiHFplusEta4);
tree_->Branch("hiHFminusEta4",&hiHFminusEta4);
tree_->Branch("hiHFhit",&hiHFhit);
tree_->Branch("hiHFhitPlus",&hiHFhitPlus);
tree_->Branch("hiHFhitMinus",&hiHFhitMinus);
tree_->Branch("hiHFECut",&hiHFECut);
tree_->Branch("hiHFECutPlus",&hiHFECutMinus);
tree_->Branch("hiEB",&hiEB);
tree_->Branch("hiET",&hiET);
tree_->Branch("hiEE",&hiEE);
tree_->Branch("hiEEplus",&hiEEplus);
tree_->Branch("hiEEminus",&hiEEminus);
tree_->Branch("hiZDC",&hiZDC);
tree_->Branch("hiZDCplus",&hiZDCplus);
tree_->Branch("hiZDCminus",&hiZDCminus);
tree_->Branch("BSx",&BSx);
tree_->Branch("BSy",&BSy);
tree_->Branch("BSz",&BSz);
tree_->Branch("BSdx",&BSdx);
tree_->Branch("BSdy",&BSdy);
tree_->Branch("BSdz",&BSdz);
tree_->Branch("BSdxdz",&BSdxdz);
tree_->Branch("BSsigmaZ",&BSsigmaZ);
tree_->Branch("BSdsigmaZ",&BSdsigmaZ);
//tree_->Branch("MuonsDCA",&MuonsDCA);
//tree_->Branch("vtxProb_dimuon",&vtxProb_dimuon);
//tree_->Branch("CosAlpha",&CosAlpha);


  
}


effAnalyzer::~effAnalyzer()
{

   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}




// ------------ method called for each event  ------------
void
effAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    using namespace std;
    using namespace edm;
    using namespace reco;
    using namespace trigger;

    TString mu_filters[2] = {"hltL1sSingleMu0NotMBHF2AND","hltL1sSingleMuOpenNotMBHF2AND"}; 
    
    edm::Handle<View<reco::Vertex>> pv;
    iEvent.getByToken(primaryvertexTok, pv);
     
   if (pv->empty()) return; // skip the event if no PV found     
   const reco::Vertex &pv_track = pv->front();
   nPV_    = pv->size();
   good_vertices_ = 0;
   if (pv.isValid())
    if (pv->size() > 0)
      for (auto v : *pv)
        if (v.ndof() >= 4 && !v.isFake())
          ++good_vertices_;
  pvNTracks_ = pv_track.nTracks();
  

   if(isMCstudy_)
                       {
                           edm::Handle< GenEventInfoProduct > genWeightH;
                           iEvent.getByToken(genEventInfoProductTok,genWeightH);
                           genWeight_ = genWeightH->GenEventInfoProduct::weight();
                        }

                  run_ = iEvent.id().run();

  


    edm::Handle<edm::TriggerResults> hltresults;
    iEvent.getByToken(triggerresultsTok, hltresults);
  
          triggerPath.clear();
          triggerDecision.clear();

          const edm::TriggerNames &names = iEvent.triggerNames(*hltresults);
          for(unsigned int iPath=0 ; iPath < pathsToSave_.size(); iPath++){
                               TString path = pathsToSave_.at(iPath);
                               bool trigDec(false);
                               size_t j;
                               for (j=0; j < hltresults->size(); j++) {
                                                        if (TString(names.triggerName(j)).Contains(path)){
                                                                               if (hltresults->accept(j)) {
                                                                 trigDec = true;
	                                             }
                                } 
                     }
                   j=0;
                   triggerPath.push_back(path.Data());
                   triggerDecision.push_back(trigDec);
                   //cout<<"path : "<<path<<"    , Decision : "<<triggerDecision[iPath]<<endl;
             }
 


           edm::Handle<trigger::TriggerEvent> trigsummaryinfo;
           iEvent.getByToken(trigsummaryTok, trigsummaryinfo);

            trigger::TriggerObjectCollection allTriggerObjects;
            allTriggerObjects = trigsummaryinfo->getObjects();
            int numberOfFilters = filterToMatch_.size();
            trigger::TriggerObjectCollection *legObjects = new trigger::TriggerObjectCollection[numberOfFilters];          
            for (size_t iteFilter=0; iteFilter<filterToMatch_.size(); iteFilter++) 
                        {
	                                     edm::InputTag filterTag = edm::InputTag(filterToMatch_.at(iteFilter), "", HLTprocess_);
                                             size_t filterIndex = (*trigsummaryinfo).filterIndex(filterTag);
                                             if (filterIndex < (*trigsummaryinfo).sizeFilters())
                                {
                                               //check if the trigger object is present
                                              //cout<<"filterIndex : "<<filterIndex<<"   , filterName :  "<<(*trigsummaryinfo).filterLabel(filterIndex)<<"  , filterTag : "<<filterTag<<endl;
                                              const trigger::Keys &keys = (*trigsummaryinfo).filterKeys(filterIndex);
                                              for (size_t j = 0; j < keys.size(); j++) 
                                    {
                trigger::TriggerObject foundObject = (allTriggerObjects)[keys[j]];
                legObjects[iteFilter].push_back(foundObject);
             }
          }
       }
     
   


         edm::Handle< View<reco::Muon>> muons;
         iEvent.getByToken(muonTok, muons);
      mu_pt_.clear();

     mu_eta_.clear();
     mu_phi_.clear();
     mu_energy_.clear();
     mu_charge_.clear();
     mu_type_.clear();
     mu_d0_.clear();
     mu_dz_.clear();
     mu_SIP_.clear();
     mu_Chi2NDF_.clear();
     mu_InnerD0_.clear();
     mu_InnerDz_.clear();
     mu_TrkLayers_.clear();
     mu_PixelLayers_.clear();
     mu_PixelHits_.clear();
     mu_MuonHits_.clear();
     mu_Stations_.clear();
     mu_Matches_.clear();
     mu_TrkQuality_.clear();
     mu_IsoTrk_.clear();
     mu_PFChIso_.clear();
     mu_PFPhoIso_.clear();
     mu_PFNeuIso_.clear();
     mu_PFPUIso_.clear();
     mu_PFChIso03_.clear();
     mu_PFPhoIso03_.clear();
     mu_PFNeuIso03_.clear();
     mu_PFPUIso03_.clear();
     mu_InnervalidFraction_.clear();
     mu_segmentCompatibility_.clear();  
     mu_chi2LocalPosition_.clear(); 
     mu_trkKink_.clear();
     mu_BestTrkPtError_.clear();
     mu_BestTrkPt_.clear();
     mu_BestTrkType_.clear();

     mu_CutBasedIdLoose_.clear();
     mu_CutBasedIdMedium_.clear();
     mu_CutBasedIdTight_.clear();
     mu_CutBasedIdMediumPrompt_.clear();
     mu_CutBasedIdGlobalHighPt_.clear();
     mu_CutBasedIdTrkHighPt_.clear();
     mu_PFIsoVeryLoose_.clear();
     mu_PFIsoLoose_.clear();
     mu_PFIsoMedium_.clear();  
     mu_PFIsoTight_.clear();
     mu_PFIsoVeryTight_.clear();
     mu_PFIsoVeryVeryTight_.clear();
     mu_TrkIsoLoose_.clear();  
     mu_TrkIsoTight_.clear();  
     mu_SoftCutBasedId_.clear();
     mu_MvaLoose_.clear();  
     mu_MvaMedium_.clear(); 
     mu_MvaTight_.clear();  
     mu_MiniIsoLoose_.clear(); 
     mu_MiniIsoMedium_.clear();
     mu_MiniIsoTight_.clear(); 
     mu_MiniIsoVeryTight_.clear();
     mu_TriggerIdLoose_.clear();
     mu_InTimeMuon_.clear();
     mu_MultiIsoLoose_.clear();
     mu_MultiIsoMedium_.clear();

     passFilter_trigOpen.clear();
     passFilter_trigNotOpen.clear();
    
    for(unsigned i=0; i < muons->size();++i ) {
       const auto mu = muons->ptrAt(i);
                  bool opentrig = false;
               bool notopentrig = false;
            //trigmatching
            for (unsigned int iteTrigObj = 0 ; iteTrigObj < filterToMatch_.size() ; iteTrigObj++){
                   bool foundTheLeg = false;
                   TString filter = filterToMatch_.at(iteTrigObj);
                   int iPass[[maybe_unused]] = 0;
          for (unsigned int i = 0 ; i < legObjects[iteTrigObj].size() ; i++){
                  double delR = deltaR(legObjects[iteTrigObj].at(i).eta(), legObjects[iteTrigObj].at(i).phi(),mu->eta(),mu->phi());
                  //std::cout<<"Delta R : ="<<delR<<"\n";
              if (delR<0.3) {
               foundTheLeg = true;
               iPass = i;
               break;
              }
          }

          if(mu_filters[0].Contains(filter) && foundTheLeg) { opentrig = true;}
          if(mu_filters[1].Contains(filter) && foundTheLeg)  {notopentrig = true; }
  }

       passFilter_trigOpen.push_back(opentrig);
       passFilter_trigNotOpen.push_back(notopentrig);


      nMuons_++;
     // float muonIso = (mu->pfIsolationR04().sumChargedHadronPt + max(0., mu->pfIsolationR04().sumNeutralHadronEt + mu->pfIsolationR04().sumPhotonEt - 0.5*mu->pfIsolationR04().sumPUPt))/mu->pt();


    mu_pt_    .push_back(mu->pt());
    mu_energy_.push_back(mu->energy());
    mu_eta_   .push_back(mu->eta());
    mu_phi_   .push_back(mu->phi());
    mu_charge_.push_back(mu->charge());
    mu_type_  .push_back(mu->type());
    mu_d0_    .push_back(mu->muonBestTrack()->dxy(pv_track.position()));
    mu_dz_    .push_back(mu->muonBestTrack()->dz(pv_track.position()));
   // mu_SIP_   .push_back(fabs(mu->dB(pat::Muon::PV3D))/mu->edB(pat::Muon::PV3D));
    mu_BestTrkPtError_         .push_back(mu->muonBestTrack()->ptError());
    mu_BestTrkPt_             .push_back(mu->muonBestTrack()->pt());
    mu_BestTrkType_           .push_back(mu->muonBestTrackType());
    mu_segmentCompatibility_  .push_back(mu->caloCompatibility());//(mu->segmentCompatibility());
    mu_chi2LocalPosition_     .push_back(mu->combinedQuality().chi2LocalPosition);
    mu_trkKink_               .push_back(mu->combinedQuality().trkKink);

    const reco::TrackRef glbmu = mu->globalTrack();
    const reco::TrackRef innmu = mu->innerTrack();


   if (glbmu.isNull()) {
      mu_Chi2NDF_ .push_back(-99.);
      mu_MuonHits_.push_back(-99);
    } else {
      mu_Chi2NDF_.push_back(glbmu->normalizedChi2());
      mu_MuonHits_.push_back(glbmu->hitPattern().numberOfValidMuonHits());
    }

    if (innmu.isNull()) {
      mu_InnerD0_     .push_back(-99.);
      mu_InnerDz_     .push_back(-99.);
      mu_TrkLayers_   .push_back(-99);
      mu_PixelLayers_ .push_back(-99);
      mu_PixelHits_   .push_back(-99);
      mu_TrkQuality_  .push_back(-99);
      mu_InnervalidFraction_ .push_back(-99);
    } else {
      mu_InnerD0_     .push_back(innmu->dxy(pv_track.position()));
      mu_InnerDz_     .push_back(innmu->dz(pv_track.position()));
      mu_TrkLayers_   .push_back(innmu->hitPattern().trackerLayersWithMeasurement());
      mu_PixelLayers_ .push_back(innmu->hitPattern().pixelLayersWithMeasurement());
      mu_PixelHits_   .push_back(innmu->hitPattern().numberOfValidPixelHits());
      mu_TrkQuality_  .push_back(innmu->quality(reco::TrackBase::highPurity));
      mu_InnervalidFraction_ .push_back(innmu->validFraction());
    }

    mu_Stations_   .push_back(mu->numberOfMatchedStations());
    mu_Matches_    .push_back(mu->numberOfMatches());
   // mu_IsoTrk_     .push_back(mu->trackIso());
    mu_PFChIso_    .push_back(mu->pfIsolationR04().sumChargedHadronPt);
    mu_PFPhoIso_   .push_back(mu->pfIsolationR04().sumPhotonEt);
    mu_PFNeuIso_   .push_back(mu->pfIsolationR04().sumNeutralHadronEt);
    mu_PFPUIso_    .push_back(mu->pfIsolationR04().sumPUPt);
    mu_PFChIso03_  .push_back(mu->pfIsolationR03().sumChargedHadronPt);
    mu_PFPhoIso03_ .push_back(mu->pfIsolationR03().sumPhotonEt);
    mu_PFNeuIso03_ .push_back(mu->pfIsolationR03().sumNeutralHadronEt);
    mu_PFPUIso03_  .push_back(mu->pfIsolationR03().sumPUPt);

     mu_CutBasedIdLoose_. 	push_back(mu->passed(reco::Muon::CutBasedIdLoose));
     mu_CutBasedIdMedium_.	push_back(mu->passed(reco::Muon::CutBasedIdMedium));
     mu_CutBasedIdTight_.	push_back(mu->passed(reco::Muon::CutBasedIdTight));
     mu_CutBasedIdMediumPrompt_.push_back(mu->passed(reco::Muon::CutBasedIdMediumPrompt));
     mu_CutBasedIdGlobalHighPt_.push_back(mu->passed(reco::Muon::CutBasedIdGlobalHighPt));
     mu_CutBasedIdTrkHighPt_.	push_back(mu->passed(reco::Muon::CutBasedIdTrkHighPt));
     mu_PFIsoVeryLoose_.	push_back(mu->passed(reco::Muon::PFIsoVeryLoose));
     mu_PFIsoLoose_.		push_back(mu->passed(reco::Muon::PFIsoLoose));
     mu_PFIsoMedium_.		push_back(mu->passed(reco::Muon::PFIsoMedium));  
     mu_PFIsoTight_.		push_back(mu->passed(reco::Muon::PFIsoTight));
     mu_PFIsoVeryTight_.	push_back(mu->passed(reco::Muon::PFIsoVeryTight));

     mu_TrkIsoLoose_.		push_back(mu->passed(reco::Muon::TkIsoLoose));  
     mu_TrkIsoTight_.		push_back(mu->passed(reco::Muon::TkIsoTight));  
     mu_SoftCutBasedId_.	push_back(mu->passed(reco::Muon::SoftCutBasedId));
     mu_MvaLoose_.		push_back(mu->passed(reco::Muon::MvaLoose));  
     mu_MvaMedium_.		push_back(mu->passed(reco::Muon::MvaMedium)); 
     mu_MvaTight_.		push_back(mu->passed(reco::Muon::MvaTight));
     mu_MiniIsoLoose_.		push_back(mu->passed(reco::Muon::MiniIsoLoose)); 
     mu_MiniIsoMedium_.		push_back(mu->passed(reco::Muon::MiniIsoMedium));
     mu_MiniIsoTight_.		push_back(mu->passed(reco::Muon::MiniIsoTight)); 
     mu_MiniIsoVeryTight_.	push_back(mu->passed(reco::Muon::MiniIsoVeryTight));

}


    edm::Handle<edm::View<reco::Track>> trackinfo;
    iEvent.getByToken(trackTok, trackinfo);
     
   edm::Handle<int> cbin_;
   iEvent.getByToken(CentralityBinSrcTok,cbin_);
   hiBin = *cbin_;
     
   hiNpix.clear();    hiNpixelTracks.clear();   hiNtracks.clear();     hiNtracksPtCut.clear();  hiNtracksEtaCut.clear();    hiNtracksEtaPtCut.clear();    hiNpixPlus.clear();   hiNpixMinus.clear();
   hiNpixelTracksPlus.clear();    hiNpixelTracksMinus.clear();    hiHF.clear();      hiHFplus.clear();     hiHFminus.clear();      hiHFplusEta4.clear();    hiHFminusEta4.clear();     hiHFhit.clear();
     hiHFhitPlus.clear();     hiHFhitMinus.clear();      hiHFECut.clear();     hiHFECutPlus.clear();     hiHFECutMinus.clear();     hiEB.clear();      hiET.clear(); hiEE.clear();     hiEEplus.clear();
    hiEEminus.clear();     hiZDC.clear();      hiZDCplus.clear();      hiZDCminus.clear(); 
  
   edm::Handle<reco::Centrality> centrality;
   iEvent.getByToken(CentralityTok, centrality);
    
    hiNpix.push_back(centrality->multiplicityPixel());
    hiNpixPlus.push_back(centrality->multiplicityPixelPlus());
    hiNpixMinus.push_back(centrality->multiplicityPixelMinus());
    hiNpixelTracks.push_back(centrality->NpixelTracks());
    hiNpixelTracksPlus.push_back(centrality->NpixelTracksPlus());
    hiNpixelTracksMinus.push_back(centrality->NpixelTracksMinus());
    hiNtracks.push_back(centrality->Ntracks());
    hiNtracksPtCut.push_back(centrality->NtracksPtCut());
    hiNtracksEtaCut.push_back(centrality->NtracksEtaCut());
    hiNtracksEtaPtCut.push_back(centrality->NtracksEtaPtCut());
    hiHF.push_back(centrality->EtHFtowerSum());
    hiHFplus.push_back(centrality->EtHFtowerSumPlus());
    hiHFminus.push_back(centrality->EtHFtowerSumMinus());
    hiHFECut.push_back(centrality->EtHFtowerSumECut());
    hiHFECutPlus.push_back(centrality->EtHFtowerSumECutPlus());
    hiHFECutMinus.push_back(centrality->EtHFtowerSumECutMinus());
    hiHFplusEta4.push_back(centrality->EtHFtruncatedPlus());
    hiHFminusEta4.push_back(centrality->EtHFtruncatedMinus());
    hiHFhit.push_back(centrality->EtHFhitSum());
    hiHFhitPlus.push_back(centrality->EtHFhitSumPlus());
    hiHFhitMinus.push_back(centrality->EtHFhitSumMinus());
    hiZDC.push_back(centrality->zdcSum());
    hiZDCplus.push_back(centrality->zdcSumPlus());
    hiZDCminus.push_back(centrality->zdcSumMinus());

    hiEEplus.push_back(centrality->EtEESumPlus());
    hiEEminus.push_back(centrality->EtEESumMinus());
    hiEE.push_back(centrality->EtEESum());
    hiEB.push_back(centrality->EtEBSum());
    hiET.push_back(centrality->EtMidRapiditySum());






               


                      genMuon_pt.clear();genMuon_eta.clear();genMuon_phi.clear();genMuon_energy.clear();
                      edm::Handle<edm::View<reco::GenParticle>> genpart;
                      if(isMCstudy_)
                           {
                                 iEvent.getByToken(geninfoTok, genpart);
                                 for(unsigned int n = 0; n< genpart->size(); ++n){
                                 const reco::GenParticle & genMuon = (*genpart)[n];
                                 if (std::abs(genMuon.pdgId()) != 13 || genMuon.status() != 1) continue; 
                                 genMuon_pt.push_back(genMuon.pt());
	                         genMuon_eta.push_back(genMuon.eta());
	                         genMuon_phi.push_back(genMuon.phi());
	                         genMuon_energy.push_back(genMuon.energy());
                              }
                          }
    
    

                   edm::ESHandle<MagneticField> magneticField;
                   iSetup.get<IdealMagneticFieldRecord>().get(magneticField);
                   magneticField_ = &*magneticField;

 BSx.clear();BSy.clear();BSz.clear();BSdx.clear();BSdy.clear();BSdz.clear();BSdxdz.clear();BSdydz.clear();BSsigmaZ.clear();BSdsigmaZ.clear();

   edm::Handle<reco::BeamSpot> vertexBeamSpot ;
   iEvent.getByToken(offlineBSTok,vertexBeamSpot);
         BSx.push_back(vertexBeamSpot->x0()); 
         BSy.push_back(vertexBeamSpot->y0());
         BSz.push_back(vertexBeamSpot->z0());
         BSdxdz.push_back(vertexBeamSpot->dxdz());
         BSdydz.push_back(vertexBeamSpot->dydz());

     /*std::vector<TLorentzVector> trackingMuons_pos;
     std::vector<TLorentzVector> trackingMuons_neg;
    for(unsigned int k =0; k < trackinfo->size() ; ++k)
       {  
          const reco::Track & track1 = (*trackinfo)[k];
          if(track1.charge() < 0)continue;
          if(track1.pt() < 1.0) continue;
          if(fabs(track1.eta()) > 2.4) continue;
          if(!track1.quality(reco::TrackBase::highPurity))continue;
          if(track1.numberOfValidHits() < 1)continue;
          TLorentzVector track1_lv;
          track1_lv.SetPtEtaPhiM(track1.pt(), track1.eta(), track1.phi(), nominalMuonMass);
          trackingMuons_pos.push_back(TLorentzVector(track1_lv));     
         

         for(unsigned int l =0; l < trackinfo->size() ; ++l)
             {
                const reco::Track & track2 = (*trackinfo)[l];
          if(track2.charge() > 0)continue;
          if(track2.pt() < 1.0) continue;
          if(fabs(track2.eta()) > 2.4) continue;
          if(!track2.quality(reco::TrackBase::highPurity))continue;
          if(track2.numberOfValidHits() < 1)continue;
          TLorentzVector track2_lv;
          track2_lv.SetPtEtaPhiM(track2.pt(), track2.eta(), track2.phi(), nominalMuonMass);
          trackingMuons_neg.push_back(TLorentzVector(track2_lv));          

      
}             
      }


    

        for (unsigned int j =0 ; j< muons->size(); ++j)
            {
                 const reco::Muon & muon1_trk = (*muons)[j];
                 if(muon1_trk.charge()< 0)continue;
                 if(muon1_trk.pt() < 1.0) continue;
                 if(fabs(muon1_trk.eta()) > 2.4) continue;
                 TrackRef intracktag = muon1_trk.innerTrack();
                 if(intracktag.isNull())continue;
                 if(!muon1_trk.isGlobalMuon())continue;
                 if(!(muon1_trk.passed(reco::Muon::SoftCutBasedId)))continue;
                 if(!(muon1_trk.passed(reco::Muon::TkIsoLoose)))continue;
                 bool trackingMatch_tag = false;
             for (unsigned int trackindex=0; trackindex< trackingMuons_pos.size(); ++trackindex)
                {
                        deltaR_Trk_Tag = ROOT::Math::VectorUtil::DeltaR(muon1_trk.p4(),trackingMuons_pos.at(trackindex));
                        if (ROOT::Math::VectorUtil::DeltaR(muon1_trk.p4(),trackingMuons_pos.at(trackindex)) < 0.7) trackingMatch_tag = true;
                 }
                 if (!trackingMatch_tag) continue;



       for (unsigned int l =0 ; l< muons->size(); ++l)
         {
              const reco::Muon & muon2_trk = (*muons)[l];
              if(muon2_trk.charge() > 0)continue;             
              if(muon2_trk.pt() < 1.0) continue;
              if(fabs(muon2_trk.eta()) > 2.4) continue;
              TrackRef intracktag2 = muon2_trk.innerTrack();
              if(intracktag2.isNull())continue;
              //if(!muon2_trk.isGlobalMuon())continue;
              if(!muon2_trk.isStandAloneMuon())continue;
              if(!(muon1_trk.passed(reco::Muon::SoftCutBasedId)))continue;
              trkmuon_pt_all = muon2_trk.pt(); trkmuon_eta_all = muon2_trk.eta(); trkmuon_phi_all = muon2_trk.phi();
               //std::cout<<"pT :: "<<trkmuon_pt_all<<"\t"<<"eta :: "<<trkmuon_eta_all<<"\t"<<"phi :: "<<trkmuon_phi_all<<"\n";
              TLorentzVector tracktagleg, trackprobeleg;
              tracktagleg.SetPtEtaPhiM(muon1_trk.pt(), muon1_trk.eta(), muon1_trk.phi(), nominalMuonMass);
              trackprobeleg.SetPtEtaPhiM(muon2_trk.pt(), muon2_trk.eta(), muon2_trk.phi(), nominalMuonMass);
              TLorentzVector trk_invdimuon = tracktagleg + trackprobeleg;
             if(abs(trk_invdimuon.M()-nominalJpsiMass) > JpsiMassWindow)continue;
              //if( trk_invdimuon.M() < 7.00 && trk_invdimuon.M() > 200)continue;
              trkDiMuon_all = trk_invdimuon.M();
              hists_1d_["h_trkmll_all"]->Fill(trk_invdimuon.M());

             bool trackingMatch_probe = false;
             for (unsigned int trackindex2=0; trackindex2< trackingMuons_neg.size(); ++trackindex2)
               {
                  deltaR_Trk_Probe = ROOT::Math::VectorUtil::DeltaR(muon2_trk.p4(),trackingMuons_neg.at(trackindex2));
                  if (fabs(muon2_trk.eta() - trackingMuons_neg.at(trackindex2).Eta())> 0.2)continue;
                  if (ROOT::Math::VectorUtil::DeltaR(muon2_trk.p4(),trackingMuons_neg.at(trackindex2)) < 0.7) trackingMatch_probe = true;
             }
       
           if(trackingMatch_probe)
                 { 
                   trkmuon_pt_pass = muon2_trk.pt(); 
                   trkmuon_eta_pass = muon2_trk.eta(); 
                   trkmuon_phi_pass = muon2_trk.phi();
                   trkDiMuon_pass = trk_invdimuon.M();
                   hists_1d_["h_trkmll_pass"]->Fill(trk_invdimuon.M());
                  }
            else
               {
                 trkmuon_pt_fail = muon2_trk.pt(); 
                 trkmuon_eta_fail = muon2_trk.eta(); 
                 trkmuon_phi_fail = muon2_trk.phi();
                 trkDiMuon_fail = trk_invdimuon.M();
                 hists_1d_["h_trkmll_fail"]->Fill(trk_invdimuon.M());
               }

   
       }
    }


        trigger::TriggerObjectCollection allTriggerObjects;
        trigger::TriggerObjectCollection selectedObjects;
    
    
    TLorentzVector mtrk;
    std::vector<TLorentzVector> trigMuons;
    const  edm::TriggerNames & triggernames = iEvent.triggerNames(*hltresults);
    int ntrigs = hltresults->size();
   
        size_t filterIndex = (*trigsummaryinfo).filterIndex(filtertag);
        allTriggerObjects = trigsummaryinfo->getObjects();
        if (filterIndex < (*trigsummaryinfo).sizeFilters())
        { 
          const trigger::Keys &keys = (*trigsummaryinfo).filterKeys(filterIndex);
          for (size_t j = 0; j < keys.size(); j++)
           {
            trigger::TriggerObject foundObject = (allTriggerObjects)[keys[j]];
            selectedObjects.push_back(foundObject);
            mtrk.SetPtEtaPhiM(selectedObjects[j].pt(), selectedObjects[j].eta(), selectedObjects[j].phi(), nominalMuonMass);
            trigMuons.push_back(TLorentzVector(mtrk));
            //std::cout<<"  -pt "<< selectedObjects[j].pt()<<" -eta "<<selectedObjects[j].eta()<<" -phi "<<selectedObjects[j].phi()<<"\n";
           }
        }

*/

    
    edm::View<reco::Vertex>::const_iterator vertex ;
    for ( edm::View<reco::Vertex>::const_iterator vtx = pv->begin(); vtx != pv->end(); ++vtx ) {
      if (  !vtx->isFake() && vtx->ndof()>=4. && vtx->position().Rho()<=6.0 && fabs(vtx->position().Z())<=24.0 ) {
        if (vertex == pv->end()) {
      vertex = vtx;
      
      break;
        }
      }
    }
    

          
                         
                            


                              /*TransientTrack probeTrkTT(probeTrkRef, magneticField_);
                              if(tagTrkTT.numberOfValidHits() <= 0) continue;
                              if(probeTrkTT.numberOfValidHits() <= 0) continue;
                              std::vector<TransientTrack> allTrk;
                              allTrk.push_back(tagTrkTT);
                              allTrk.push_back(probeTrkTT);
                              if(allTrk.size() <  2 )continue;
                              KalmanVertexFitter kvf(true);
                              TransientVertex tv = kvf.vertex(allTrk);

                              Vertex vertex = tv;
                              vtxProb_dimuon = TMath::Prob(vertex.chi2(),(int)vertex.ndof());
                              math::XYZVector  pperp(muon_tag.px() + muon_probe.px(), muon_tag.py() + muon_probe.py(), 0.);
                              reco::Vertex::Point  vpoint = vertex.position(); 
                              GlobalPoint secondaryVertex (vpoint.x(), vpoint.y(), vpoint.z());
                            // std::cout<<"Meku tastar guitara knhor aii aiia ii ai mia more"<<vpoint.x()<<"\n";
              GlobalPoint displacementFromBeamspot( -1*((BSx -  secondaryVertex.x()) +  (secondaryVertex.z() - BSz) * BSdxdz),-1*((BSy - secondaryVertex.y())+  (secondaryVertex.z() - BSz) * BSdydz), 0);
                              reco::Vertex::Point vperp(displacementFromBeamspot.x(),displacementFromBeamspot.y(),0.);
                              CosAlpha = vperp.Dot(pperp)/(vperp.R()*pperp.R());        
                              TrajectoryStateClosestToPoint tagTS = tagTrkTT.impactPointTSCP();
                              TrajectoryStateClosestToPoint probeTS = probeTrkTT.impactPointTSCP(); 
                             if (tagTS.isValid() && probeTS.isValid()) {
       
                                                                                ClosestApproachInRPhi cApp;
                                                                                cApp.calculate(tagTS.theState(), probeTS.theState());
                                                                                MuonsDCA = cApp.distance();
                                                                                //std::cout<<"Bailando, bailando.. "<<MuonsDCA<<"\n";
                                                                        }

         

                    //reco::CompositeCandidate dimuon;
                    //dimuon.addDaughter(muon_tag);
                    //dimuon.addDaughter(muon_probe);
                    //AddFourMomenta fourvec;
                    //fourvec.set(dimuon); 
         TLorentzVector tagleg, probeleg;
         tagleg.SetPtEtaPhiM(muon_tag.pt(), muon_tag.eta(), muon_tag.phi(), nominalMuonMass);
         probeleg.SetPtEtaPhiM(muon_probe.pt(), muon_probe.eta(), muon_probe.phi(), nominalMuonMass);
         TLorentzVector dimuon = tagleg+probeleg;
         if(abs(dimuon.M()-nominalJpsiMass) > JpsiMassWindow)continue;
         //if(dimuon.M() < 7.00 && dimuon.M() > 200)continue;
         trigDiMuon_all = dimuon.M();
         hists_1d_["h_trigmll_all"]->Fill(dimuon.M());
         fillHists(LorentzVector(muon_probe.p4()),"probe_all"); 
         trigmuon_pt_all = muon_probe.pt(); trigmuon_eta_all = muon_probe.eta(); trigmuon_phi_all = muon_probe.phi();
           

         bool trigmatch_probe = false;
          
         for (unsigned int trigindex=0; trigindex < trigMuons.size(); ++trigindex) {
           if (ROOT::Math::VectorUtil::DeltaR(muon_probe.p4(),trigMuons.at(trigindex)) < dr_trigmatch_wider) trigmatch_probe = true;
           }
         
         
      if (trigmatch_probe)
               {
                           trigmuon_pt_pass = muon_probe.pt(); 
                           trigmuon_eta_pass = muon_probe.eta(); 
                           trigmuon_phi_pass = muon_probe.phi();
                           trigDiMuon_pass = dimuon.M();
                           fillHists(LorentzVector(muon_probe.p4()),"probe_pass");
                           hists_1d_["h_trigmll_pass"]->Fill(dimuon.M());
               }
        else 
              { 
                       trigmuon_pt_fail = muon_probe.pt();
                       trigmuon_eta_fail = muon_probe.eta(); 
                       trigmuon_phi_fail = muon_probe.phi();
                       trigDiMuon_fail = dimuon.M();
                       fillHists(LorentzVector(muon_probe.p4()),"probe_fail");
                       hists_1d_["h_trigmll_fail"]->Fill(dimuon.M());
              }
     }
     }
    */
    tree_->Fill();

#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif

#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
    
    
}
void effAnalyzer::bookHists(edm::Service<TFileService>& fs, const std::string& suffix) {

  std::string suf(suffix);
  if (suffix.size()) suf = "_"+suffix;

  hists_1d_["h_pt"+suf] = fs->make<TH1F>(Form("h_pt%s",suf.c_str()) , "; p_{T} [GeV]" , 20 , 0. , 20. );
  hists_1d_["h_eta"+suf] = fs->make<TH1F>(Form("h_eta%s",suf.c_str()) , "; #eta" , 20 , -2.4 , 2.4 );
  hists_1d_["h_phi"+suf] = fs->make<TH1F>(Form("h_phi%s",suf.c_str()) , "; #phi" , 20 , -TMath::Pi(),TMath::Pi() );

  return;
}

void effAnalyzer::fillHists(const LorentzVector& lv, const std::string& suffix) {

  std::string suf(suffix);
  if (suffix.size()) suf = "_"+suffix;

  hists_1d_["h_pt"+suf]->Fill(lv.pt());
  hists_1d_["h_eta"+suf]->Fill(lv.eta());
  hists_1d_["h_phi"+suf]->Fill(lv.phi());

  return;
}

// ------------ method called once each job just before starting event loop  ------------
void
effAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void
effAnalyzer::endJob()
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
effAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);

  //Specify that only 'tracks' is allowed
  //To use, remove the default given above and uncomment below
  //ParameterSetDescription desc;
  //desc.addUntracked<edm::InputTag>("tracks","ctfWithMaterialTracks");
  //descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(effAnalyzer);
