#define TnP_analysis_cxx
#include "TnP_analysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void TnP_analysis::Loop(TString output)
{
//   In a ROOT session, you can do:
//      root> .L TnP_analysis.C
//      root> TnP_analysis t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
if (fChain == 0) return;

  bool RunSystematic = true;
  vector<TString> systematicVar = {"nominal"};
  if(RunSystematic)
    {
      systematicVar.push_back("tagpt_up");
      systematicVar.push_back("tagpt_down");
      systematicVar.push_back("contimass_up");
      systematicVar.push_back("contimass_down");
    }

   
   for(int i=0; i<systematicVar.size();i++)
      {
      double ptTag = 2;
      double ContiMassL = 7;
      double ContiMassR = 80;
      
      if(systematicVar.at(i).Contains("TagPt_up")) ptTag = 4;
      if(systematicVar.at(i).Contains("TagPt_down")) ptTag =1 ;
      if(systematicVar.at(i).Contains("Contimass_up")) {ContiMassL = 4; ContiMassR = 90;}
      if(systematicVar.at(i).Contains("Contimass_down")) {ContiMassL = 10; ContiMassR = 70;}
      cout<<systematicVar.at(i).Data()<<endl;
      cout<<" ptTag : "<<ptTag<<" , ContiMassL : "<<ContiMassL<<" , ContiMassR : "<<ContiMassR<<endl;
      output = "";
      output +="efficiency_";
      output += systematicVar.at(i);
      output +=".root";

   Long64_t nentries = fChain->GetEntriesFast();
      
      double eta_bins[14] = {-2.4,-2.1,-1.6,-1.2,-0.8,-0.3,-0.2,0.2,0.3,0.8,1.2,1.6,2.1,2.4};
      double pt_bins_Mu0_notOpen[10] = {0,2,4,6,8,10,12,14,17,20};
      double pt_bins_Mu0_Open[10] = {0,2,4,6,8,10,12,14,17,20};
      
      TFile *file = new TFile(output.Data(),"RECREATE");
      int nbins =8;
      TH1F * massall_h[nbins];
      TH1F * masspass_h[nbins];
      for (int l = 0; l<nbins; l++){
         massall_h[l] = new TH1F(Form("massall%dth_Bin", l),Form("massall%dth_Bin; M_{#mu^{+}#mu^{-}} ; Events",l),40,7.0,80);
         masspass_h[l] = new TH1F(Form("masspass%dth_Bin", l),Form("masspass%dth_Bin; M_{#mu^{+}#mu^{-}} ; Events",l),40,7.0,80);
         
      }
      //HLT Mu0_Open
      TH1F *h_Mu0_Open_pt_total = new TH1F("Mu0_Open_pt_total","Mu0_Open_pt",9,pt_bins_Mu0_Open);
      TH1F *h_Mu0_Open_eta_total = new TH1F("Mu0_Open_eta_total","Mu0_Open_eta",13,eta_bins);
      TH2F *h_Mu0_Open_pt_eta_total = new TH2F("Mu0_Open_pt_eta_total","Mu0_Open_pt_eta",13,eta_bins,9,pt_bins_Mu0_Open);
      TH1F *h_Mu0_Open_pt_pass = new TH1F("Mu0_Open_pt_pass","Mu0_Open_pt",9,pt_bins_Mu0_Open);
      TH1F *h_Mu0_Open_eta_pass = new TH1F("Mu0_Open_eta_pass","Mu0_Open_eta",13,eta_bins);
      TH2F *h_Mu0_Open_pt_eta_pass = new TH2F("Mu0_Open_pt_eta_pass","Mu0_Open_pt_eta",13,eta_bins,9,pt_bins_Mu0_Open);
      
      TH1F *pt_mucol = new TH1F("pt_mucol", "muon pT; p_{T}^{#mu} (GeV); number of events", 50, 0, 20 );
      TH1F *eta_mucol = new TH1F("eta_mucol", "muon Eta; #eta_{#mu} (a.u.); number of events", 50, -2.5, 2.5 );
      TH1F *phi_mucol = new TH1F("phi_mucol", "muon Phi; #phi_{#mu} (rad); number of events", 50, -TMath::Pi(),TMath::Pi());
      
      TH1F *pt_mumu = new TH1F("pt_mumu", "mumu pT; p_{T}^{#mu#mu} (GeV); number of events", 50, 0, 5 );
      TH1F *eta_mumu = new TH1F("eta_mumu", "mumu Eta; #eta_{#mu#mu} (a.u.); number of events", 50, -2.5, 2.5 );
      TH1F *phi_mumu = new TH1F("phi_mumu", "mumu Phi; #phi_{#mu#mu} (rad); number of events", 50, -TMath::Pi(),TMath::Pi());
      
      TH1F *hf_h = new TH1F("hf_h","hf_h", 100, 7.0,17);
      TH1F *hfECut_h = new TH1F("hfECut_h","hfECut_h", 100, 0.0,7.0);
      
      pt_mucol->Sumw2();
      eta_mucol->Sumw2();
      phi_mucol->Sumw2();
      
      pt_mumu->Sumw2();
      eta_mumu->Sumw2();
      phi_mumu->Sumw2();
      
      
      h_Mu0_Open_pt_total->Sumw2();
      h_Mu0_Open_eta_total->Sumw2();
      h_Mu0_Open_pt_eta_total->Sumw2();
      h_Mu0_Open_pt_pass->Sumw2();
      h_Mu0_Open_eta_pass->Sumw2();
      h_Mu0_Open_pt_eta_pass->Sumw2();

      
      hf_h->Sumw2();
      hfECut_h->Sumw2();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
    //std::cout<<mu_pt->size()<<"\t"<<mu_eta->size()<<"\t"<<mu_phi->size()<<"\t"<<hiHF->size()<<"\t"<<hiHFECut->size()<<"\n";
      for(unsigned int i =0 ; i< mu_pt->size(); i++){
      pt_mucol->Fill(mu_pt->at(i));
      eta_mucol->Fill(mu_eta->at(i));
         phi_mucol->Fill(mu_phi->at(i));}
      for(unsigned int k =0 ; k< hiHF->size(); k++){
            hf_h->Fill(hiHF->at(k));
         hfECut_h->Fill(hiHFECut->at(k));}
         
      
      
      
      if(jentry % 50000 ==0)cout<<"Number of events processed : "<<jentry<<endl;
      if(nMu != 2) continue;
      
      int first  = rand()%2;
      int second = (first+1)%2;
      if(mu_charge->at(first) * mu_charge->at(second)>0)continue;
      bool tag_MuId = mu_CutBasedIdLoose->at(first) && mu_PFIsoLoose->at(first);  //should be tight
      bool tag_MuKin = mu_pt->at(first)>ptTag && fabs(mu_eta->at(first))<2.4;
      bool tag_TriggerMatch = passFilter_trigOpen->at(first);
      if(!(tag_MuId && tag_MuKin && tag_TriggerMatch))continue;
      
      
      
      bool probe_MuId = GGMM_Muon_Def(second, mu_pt->at(second));
      bool probe_MuKin = fabs(mu_eta->at(second))<2.4;
      if(!(probe_MuId && probe_MuKin)) continue;
      
      TLorentzVector tag_muLV, probe_muLV, Conti_candLV;
      tag_muLV.SetPtEtaPhiE(mu_pt->at(first), mu_eta->at(first), mu_phi->at(first), mu_energy->at(first));
      probe_muLV.SetPtEtaPhiE(mu_pt->at(second), mu_eta->at(second), mu_phi->at(second), mu_energy->at(second));
      Conti_candLV = tag_muLV + probe_muLV;
      
      
      if (Conti_candLV.M()<ContiMassL || Conti_candLV.M() >ContiMassR) continue;
      pt_mumu->Fill(Conti_candLV.Pt());
      eta_mumu->Fill(Conti_candLV.Eta());
      phi_mumu->Fill(Conti_candLV.Phi());
      if(mu_eta->at(first) >-2.4 && mu_eta->at(first) < -1.8){massall_h[0]->Fill(Conti_candLV.M());}
      if(mu_eta->at(first) >-1.8 && mu_eta->at(first) < -1.2){massall_h[1]->Fill(Conti_candLV.M());}
      if(mu_eta->at(first) >-1.2 && mu_eta->at(first) < -0.6){massall_h[2]->Fill(Conti_candLV.M());}
      if(mu_eta->at(first) >-0.6 && mu_eta->at(first) < 0.0){massall_h[3]->Fill(Conti_candLV.M());}
      if(mu_eta->at(first) >0.0 && mu_eta->at(first) < 0.6){massall_h[4]->Fill(Conti_candLV.M());}
      if(mu_eta->at(first) >0.6 && mu_eta->at(first) < 1.2){massall_h[5]->Fill(Conti_candLV.M());}
      if(mu_eta->at(first) >1.2 && mu_eta->at(first) < 1.8){massall_h[6]->Fill(Conti_candLV.M());}
      if(mu_eta->at(first) >1.8 && mu_eta->at(first) < 2.4){massall_h[7]->Fill(Conti_candLV.M());}
      h_Mu0_Open_pt_total->Fill(mu_pt->at(second));
      if(mu_pt->at(second)>2)h_Mu0_Open_eta_total->Fill(mu_eta->at(second));
      h_Mu0_Open_pt_eta_total->Fill(mu_eta->at(second),mu_pt->at(second));
      if (passFilter_trigOpen->at(second)){
         h_Mu0_Open_pt_pass->Fill(mu_pt->at(second));
         if(mu_pt->at(second)>2) h_Mu0_Open_eta_pass->Fill(mu_eta->at(second));
         h_Mu0_Open_pt_eta_pass->Fill(mu_eta->at(second),mu_pt->at(second));
         if(mu_eta->at(first) >-2.4 && mu_eta->at(first) < -1.8){masspass_h[0]->Fill(Conti_candLV.M());}
         if(mu_eta->at(first) >-1.8 && mu_eta->at(first) < -1.2){masspass_h[1]->Fill(Conti_candLV.M());}
         if(mu_eta->at(first) >-1.2 && mu_eta->at(first) < -0.6){masspass_h[2]->Fill(Conti_candLV.M());}
         if(mu_eta->at(first) >-0.6 && mu_eta->at(first) < 0.0){masspass_h[3]->Fill(Conti_candLV.M());}
         if(mu_eta->at(first) >0.0 && mu_eta->at(first) < 0.6){masspass_h[4]->Fill(Conti_candLV.M());}
         if(mu_eta->at(first) >0.6 && mu_eta->at(first) < 1.2){masspass_h[5]->Fill(Conti_candLV.M());}
         if(mu_eta->at(first) >1.2 && mu_eta->at(first) < 1.8){masspass_h[6]->Fill(Conti_candLV.M());}
         if(mu_eta->at(first) >1.8 && mu_eta->at(first) < 2.4){masspass_h[7]->Fill(Conti_candLV.M());}
         
         
      }

   }
      for ( int m =0 ; m <nbins; m++)
         {
         
         std::cout<<massall_h[m]->GetEntries()<<"\t"<<masspass_h[m]->GetEntries()<<"\n";
         
         massall_h[m]->Write(Form("massall_%d_bin",m));
         masspass_h[m]->Write(Form("masspass_%d_bin",m));
         
         }
      file->Write();
      }
   cout<<"program ends"<<endl;
}
bool TnP_analysis::GGMM_Muon_Def(int i, double pt)
{
   bool LooseMu = mu_CutBasedIdLoose->at(i);   // should be Loose
   bool passIsoLoose = mu_PFIsoLoose->at(i);
   bool pass_dz = mu_dz->at(i) < 30;
   
   if (!LooseMu) return false;
   if (!passIsoLoose) return false;
   if (!pass_dz) return false;
   
   if (pt <= 2){
      if (mu_d0->at(i) > 1) return false;
   }
   else {
      if (mu_d0->at(i) > 1.5) return false;
   }
   
   return true;
}
