#include "TFile.h"
#include "TTree.h"
#include "TH2D.h"
#include "TCanvas.h"

void read()
{
    // open the file and get the tree
    TFile *file = new TFile("tree_file.root", "READ");
    TTree *tree = (TTree *)file->Get("tree");

    // define variables to hold the branches
    double px, py, pz, magnitude;
    tree->SetBranchAddress("px", &px);
    tree->SetBranchAddress("py", &py);
    tree->SetBranchAddress("pz", &pz);
    tree->SetBranchAddress("magnitude", &magnitude);

    // create a 2D histogram for px vs py
    TH2D *h_px_py = new TH2D("h_px_py", "px vs py;px;py", 100, -0.1, 0.1, 100, -0.1, 0.1);

    // loop over all entries in the tree
    for (Long64_t i = 0; i < 10000; ++i) {
        tree->GetEntry(i);
        h_px_py->Fill(px, py);
    }

    // draw the histograms
    TCanvas *c1 = new TCanvas("c1", "px vs py", 800, 600);
    h_px_py->Draw("COLZ");

    TCanvas *c2 = new TCanvas("c2", "px*py vs pz", 800, 600);
    tree->Draw("px*py:pz", "magnitude > 0.02", "COLZ");
    
}
