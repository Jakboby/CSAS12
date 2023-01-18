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
  itemType temp;
  for (int i = 0; i < list.size() - 1; i++)
    {
      if (list[i].GTIN_UPC > list[i + 1].GTIN_UPC)
      {
        temp = list[i];
        list[i] = list[i+1];
        list[i+1] = temp;
      }
    }
}
