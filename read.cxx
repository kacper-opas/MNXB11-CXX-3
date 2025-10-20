oid read(){
// initialize your object
// open your file
// get your tree
// remember to set the branch address
for (Int_t i{0}; i<N; i++){ // loop over the whole tree
tree->GetEntry(i);
// do something
}
}