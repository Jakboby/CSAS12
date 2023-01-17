void readFile( ifstream & inFile, vector<itemType> &item){
while(!inFile.eof()){
  itemType record;
  void** stuff = {&record.NDB_NO, &record.Long_name, NULL, &record.GTIN_UPC, &record.Manufacturer, NULL, NULL, &record.Ingredients};
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
      stuff[pos][0] = atoi(sub);
    }
    else if (type[pos] == str) {
      stuff[pos][0] = sub;
    }
    else if (type[pos] == ldb) {
      stuff[pos][0] = atold(sub)
    }
    else if (type[pos] == settype) {
      string subsub = "";
      for (int splooky = 0; splooky < sub.size(); splooky++) {
        if (sub[splooky] == ",") {
          stuff[pos][0].insert(subsub);
          subsub = "";
        }
        else {
          subsub += sub[splooky];
        }
      }
      stuff[pos][0].insert(subsub);
    }
    pos++;
  }
  items.push_back(record);
}

  
}
