## 1. 文法

**Range-based for loop (範囲 for 文)** [ref](https://cpprefjp.github.io/lang/cpp11/range_based_for.html)

```
for (auto &s : strArr)
{

}
```

`string`型の配列`strArr`に対して for loop を回すための文法。`&s`は配列の各要素に対する参照である。参照とせず`auto s`とするとコピーになるので元の要素の変更はできなくなる。`const &s : strArr)`のようにすることで readonly にできる。(c++11)

## 2. テクニック

**文字列操作**

特定の文字だけ削除

```
string charsToDelete = " ,.?";
for (char c : charsToDelete)
{
    s.erase(remove(s.begin(), s.end(), c), s.end());
}
```

小文字に変換

```
transform(s.begin(), s.end(), s.begin(), ::tolower);
```
