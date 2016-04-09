# KMP string match algorithm implementation

## Usage

`kmp_search(haystack, needle)`

```php
$pos = kmp_search("zjifeoabcabcjiefjie", "abcabc");
```

`kmp_prefix(needle)`

```php
$prefix = kmp_prefix("abcabc");
$pos = kmp_search_prefix("zjifeoabcabcjiefjie", $prefix);
```


## References

- KMP algorithm http://www-igm.univ-mlv.fr/~lecroq/string/node8.html
- MP algorithm http://www-igm.univ-mlv.fr/~lecroq/string/node7.html

## License

Released under MIT license
