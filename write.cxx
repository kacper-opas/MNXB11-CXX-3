#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"
#include <iostream>
#include <cmath>

void write()
{

    // create ROOT file
    TFile *file = new TFile("tree_file.root", "RECREATE");

    // create TTree
    TTree *tree = new TTree("tree", "tree");

    // variables for momentum and magnitude
    Double_t px, py, pz, magnitude;

    // create branches
    tree->Branch("px", &px);
    tree->Branch("py", &py);
    tree->Branch("pz", &pz);
    tree->Branch("magnitude", &magnitude);

    // fill the tree
    for (Int_t i = 0; i < 10000; i++)
    {
        px = gRandom->Gaus(0, 0.02);
        py = gRandom->Gaus(0, 0.02);
        pz = gRandom->Gaus(0, 0.02);

        magnitude = std::sqrt(px * px + py * py + pz * pz);

        tree->Fill();
    }

    // write and close
    tree->Write();
    file->Close();
    delete file;
}