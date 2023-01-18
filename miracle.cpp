bool openInputFile(ifstream& inFile) {
  cout << "Input file name :";
  string filename;
  do {
  getline(cin, filename);
  if(makeStringUpper(filename).compare("Q") == 0){
    return false;
  }
  inFile.open(filename);
    }
  while (!inFile.is_open() && (cout << "Try again." << endl));
  return true;
}
