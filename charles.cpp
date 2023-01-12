string makeStringUpper(string s)
{
  string upper(s.length(), ' ');
  for (int i = 0; i < s.length(); i++)
    {
      upper[i] = toupper(s[i]);
    }
  return upper;
}

void sort(vector<itemType>& list)
{
  long temp = 0;
  for (int i = 0; i < list.size(); i++)
    {
      if (list[i].GTIN_UPC > list[i + 1].GTIN_UPC)
      {
        temp = list[i].GTIN_UPC;
        list[i].GTIN_UPC = list[i+1].GTIN_UPC;
        list[i+1].GTIN_UPC = temp;
      }
    }
}
