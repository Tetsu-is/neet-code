## 1. 文法
**Range-based for loop (範囲for文)** [ref](https://cpprefjp.github.io/lang/cpp11/range_based_for.html)
```
for (auto &s : strArr)
{

}
```
`string`型の配列`strArr`に対してfor loopを回すための文法。`&s`は配列の各要素に対する参照である。参照とせず`auto s`とするとコピーになるので元の要素の変更はできなくなる。`const &s : strArr)`のようにすることでreadonlyにできる。(c++11)
