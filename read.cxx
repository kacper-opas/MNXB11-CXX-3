#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include <iostream>

void read()
{

    // open the file and get the tree
    TFile *file = new TFile("tree_file.root", "READ");
    TTree *tree = (TTree *)file->Get("tree");

    // px vs py
    TCanvas *c1 = new TCanvas("c1", "px vs py", 800, 600);
    tree->Draw("py:px", "", "COLZ");

    // px*py vs pz
    TCanvas *c2 = new TCanvas("c2", "px*py vs pz", 800, 600);
    tree->Draw("px*py:pz", "magnitude > 0.02", "COLZ");

    // close the file
    file->Close();
    delete file;
}
