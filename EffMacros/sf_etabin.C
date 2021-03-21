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


Double_t mc_eff[8];
Double_t mc_effErr[8];
Double_t data_eff[8];
Double_t  data_effErr[8];
Double_t sf[8];
Double_t sfErr[8];
Double_t etabin[8] = {-2.4,-1.8,-1.2,-0.6,0.6,1.2,1.8,2.4};
void sf_etabin()

{

   mc_eff[0]=0.529528;
   mc_eff[1]=0.58918;
   mc_eff[2]=0.869184;
   mc_eff[3]=0.921493;
   mc_eff[4]=0.92376;
   mc_eff[5]=0.86532;
   mc_eff[6]=0.586582;
   mc_eff[7]=0.531126;
    
   mc_effErr[0]=0.0670889;
   mc_effErr[1]=0.00219309;
   mc_effErr[2]=0.00286675;
   mc_effErr[3]=0.0667555;
   mc_effErr[4]=0.0738069;
   mc_effErr[5]=0.00479314;
   mc_effErr[6]=0.00215762;
   mc_effErr[7]=0.00286597;
    
   data_eff[0]=0.567072;
   data_eff[1]=0.638645;
   data_eff[2]=0.879053;
   data_eff[3]=0.884471;
   data_eff[4]=0.85498;
   data_eff[5]=0.870315;
   data_eff[6]=0.64749;
   data_eff[7]=0.567143;
    
   data_effErr[0]=0.971229;
   data_effErr[1]=0.0171506;
   data_effErr[2]=0.0238923;
   data_effErr[3]=0.0256844;
   data_effErr[4]=0.025261;
   data_effErr[5]=0.672166;
   data_effErr[6]=0.0171294;
   data_effErr[7]=0.802209;
    
    /*
     //J/\psi case
     data_eff[0]=0.806567;
     data_eff[1]=0.891624;
     data_eff[2]=0.792756;
     data_eff[3]=0.714914;
     data_eff[4]=0.800987;
     data_eff[5]=0.806128;
     data_eff[6]=0.763779;
     data_eff[7]=0.815143;
     data_effErr[0]=0.0284618;
     data_effErr[1]=0.71225;
     data_effErr[2]=0.785907;
     data_effErr[3]=0.0624597;
     data_effErr[4]=0.821915;
     data_effErr[5]=0.669876;
     data_effErr[6]=0.0440621;
     data_effErr[7]=0.0252383;
     */
   TH1D *SF_h = new TH1D("SF_h","SF_h;#eta;#epsilon(Data)/#epsilon(MC)", 8, -2.4, 2.4);
    for (int i=0; i<8; ++i )
    {
        
        sf[i] = data_eff[i]/mc_eff[i];
        sfErr[i] =sqrt(pow(data_effErr[i]/data_eff[i], 2)+ pow(mc_effErr[i]/mc_eff[i], 2));
    SF_h->SetBinContent (i+1, sf[i]);
    SF_h->SetBinError (i+1, sfErr[i]);
        std::cout<<sf[i]<<"pm"<<sfErr[i]<<"\n";
        
    }

   SF_h->Draw("colz");

}
