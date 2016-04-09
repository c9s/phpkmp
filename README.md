# KMP string match algorithm implementation

## Requirement

- PHP ^5.3

## Install

```sh
phpize 
make
make install
```


## Usage

`kmp_search(haystack, needle)`

Return value: (int) This function returns -1 if `needle` is not found in `haystack`.

```php
$pos = kmp_search("zjifeoabcabcjiefjie", "abcabc");
```

`kmp_prefix(needle)`

Return value: (resource) This function returns a resource of pre-computed prefixes array.

```php
$prefix = kmp_prefix("abcabc");
$pos = kmp_search_prefix("zjifeoabcabcjiefjie", $prefix);
```

## References

- KMP algorithm http://www-igm.univ-mlv.fr/~lecroq/string/node8.html
- MP algorithm http://www-igm.univ-mlv.fr/~lecroq/string/node7.html

## License

Released under MIT license
