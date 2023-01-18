void readFile( ifstream & inFile, vector<itemType> &item){
while(!inFile.eof()){
  itemType record;
  void* stuff[] = {&record.NDB_NO, &record.Long_Name, NULL, &record.GTIN_UPC, &record.Manufacturer, NULL, NULL, &record.Ingredients};
  enum TYPES {
    inte, str, ldb, N, settype
  };
  TYPES type[8] = {inte, str, N, ldb, str, N, N, settype};
  string temp;
  int index = 0;
  string sub;
  getline(inFile, temp);
  int pos = 0;
  while(getQuotedString(temp, index, sub)){
    if (type[pos] == inte) {
      int* temp = (int*) stuff[pos];
      *temp = stoi(sub);
    }
    else if (type[pos] == str) {
      string* temp = (string*) stuff[pos];
      *temp = sub;
    }
    else if (type[pos] == ldb) {
      long double* temp = (long double*) stuff[pos];
      *temp = stold(sub);
    }
    else if (type[pos] == settype) {
      unordered_set<string>* temp = (unordered_set<string>*) stuff[pos];
      string subsub = "";
      for (int splooky = 0; splooky < sub.size(); splooky++) {
        if (sub[splooky] == ',') {
          temp->insert(subsub);
          subsub = "";
        }
        else {
          subsub += sub[splooky];
        }
      }
      temp->insert(subsub);
    }
    pos++;
  }
  item.push_back(record);
}

  
}
