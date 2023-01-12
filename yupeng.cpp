bool findIngredient(itemType item, string ingredient){
  if(item.Ingredients.find(ingredient) != item.Ingredients.end()) {
    return true;
  } else {
    return false;
  }
}

int searchForIngredient(vector<itemType> items, string ingredient, bool printEnable) {
  vector<itemType> foundList;
  ingredient = makeStringUpper(ingredient);
  for(itemType i : items) {
    if(i.Ingredients.find(ingredient) != i.Ingredients.end()) {
      foundList.push_back(i);
    }
  }
  if(printEnable){
    sort(foundList);
    for(itemType i : foundList){
      printRecord(i);
    }
  }
  return foundList.size();
}

void printRecord(itemType& item){
  cout << "Item # " << item.NDB_NO << endl;
  cout << "Name:         " << item.Long_Name << endl;
  cout << "Manufacturer: " << item.Manufacturer << endl;
  cout << "UPC:          " << item.GTIN_UPC << endl;
  cout << "Ingredients:  ";
  for(auto itr = item.Ingredients.cbegin(); itr != item.Ingredients.cend(); itr++) {
    cout << *itr;
    if((itr + 1) != item.Ingredients.cend()){
      cout << ", ";
    } else {
      cout << ".";
    } 
  }
}
