void readFile( ifstream & inFile, vector<itemType> &item){
string line;
getline(inFile, line);
while(line != ""){
  itemType record;
  string sub;
  int index = 0;
  getQuotedString(line, index, sub);
  record.NDB_NO = stoi(sub);
  getQuotedString(line, index, sub);
  record.Long_Name = sub;
  getQuotedString(line, index, sub);
  //Ignore
  getQuotedString(line, index, sub);
  record.GTIN_UPC = atof(sub.c_str());
  cout << record.GTIN_UPC << endl;
  getQuotedString(line, index, sub);
  record.Manufacturer = sub;
  getQuotedString(line, index, sub);
  //Ignore
  getQuotedString(line, index, sub);
  //Ignore
  getQuotedString(line, index, sub);
  string subsub = "";
  for (int i = 0; i < sub.size(); i++) {
  	if (sub[i] == ',') {
  		record.Ingredients.insert(makeStringUpper(subsub));
  		subsub = "";
  	}
  	else {
  		subsub += sub[i];
  	}
  }
  record.Ingredients.insert(makeStringUpper(subsub));
  item.push_back(record);
  getline(inFile, line);
}

}
