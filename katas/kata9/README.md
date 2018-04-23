# Kata 9
###### UTF-8 Validation
### Context
A character in UTF8 can be from **1 to 4 bytes** long, subjected to the following rules:

  1. For 1-byte character, the first bit is a 0, followed by its unicode code.
  2. For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.

This is how the UTF-8 encoding would work:  
```
   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
```

Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

**Note:**
The input is an array of integers. Only the **least significant 8 bits** of each integer is used to store the data. This means each integer represents only 1 byte of data.

Example 1:
```
data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.

Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
```

Example 2:
```
data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.
```

### Break Down
This problem can be divided into 4 main cases depending on the number of bytes to consider for the UTF8 unicode to check. In all cases it is needed to check some significant bits in order to validate the data, to do this, the right shift operator `>>` can be used.
- When the unicode is **2 bytes** long, **5 digits** are needed to be **shifted**
- When the unicode is **3 bytes** long, **4 digits** are needed to be **shifted**
- When the unicode is **4 bytes** long, **3 digits** are needed to be **shifted**
- When the unicode is **1 bytes** long, **6 digits** are needed to be **shifted**

Is important to check the cases where there are more than 1 byte first in order to effectively discard the posibility of a **1** int the first bit of the UTF8 unicode.

### Solution
```
bool validUtf8(vector<int>& data) {
  int continuation_bytes = 0;
  for (int i = 0; i < data.size(); i++) {
    if (continuation_bytes == 0) {
      if ((data[i] >> 5) == 0b110) continuation_bytes = 1;
      else if ((data[i] >> 4) == 0b1110) continuation_bytes = 2;
      else if ((data[i] >> 3) == 0b11110) continuation_bytes = 3;
      else if ((data[i] >> 7)) return false; // 0xxxxxxx
    }
    else {
      if ((data[i] >> 6) != 0b10) {
        return false;
      }
      continuation_bytes--;
    }
  }

  return continuation_bytes == 0;
}

int main(int argc, char const *argv[]) {
  vector<int> data;
  data.push_back(197);
  data.push_back(130);
  data.push_back(1);
  printf("%s\n", validUtf8(data) ? "true" : "false");

  data.clear();
  data.push_back(235);
  data.push_back(140);
  data.push_back(4);
  printf("%s\n", validUtf8(data) ? "true" : "false");
  return 0;
}
```

### Analysis
This algorithm runs in `O(n)` as the number of data to inspect is the only variable that alter the complexity of it.

### Deployment
To run both examples use
```
make test
```
