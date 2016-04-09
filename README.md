# KMP string match algorithm

## Requirement

- PHP ^5.3

## Install

```sh
phpize 
make
make install
```


## Usage

### `kmp_search(string haystack, string needle)`

Return value: (`int`) This function returns -1 if `needle` is not found in `haystack`.

```php
$pos = kmp_search("zjifeoabcabcjiefjie", "abcabc");
```

### `kmp_prefix(string needle)`

Return value: (`resource`) This function returns a resource of pre-computed prefixes array. The returned resource 
can be reused when there are multiple haystacks to be searched.

```php
$prefix = kmp_prefix("abcabc");
$pos = kmp_search_prefix("zjifeoabcabcjiefjie", $prefix);
```

## References

- KMP algorithm http://www-igm.univ-mlv.fr/~lecroq/string/node8.html
- MP algorithm http://www-igm.univ-mlv.fr/~lecroq/string/node7.html

## License

Released under MIT license
