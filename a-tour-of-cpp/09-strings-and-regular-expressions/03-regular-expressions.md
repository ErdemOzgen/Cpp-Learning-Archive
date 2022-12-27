In `<regex>`, the standard library provides support for regular expressions:
- `regex_match()`: Match a regular expression against a string (of known size);
- `regex_search()`: Search for a string that matches a regular expression in an (arbitrarily long) stream of data;
 - `regex_replace()`: Search for strings that match a regular expression in an (arbitrarily long) stream of data and replace them.
 - `regex_iterator`: Iterate over matches and **submatches**
 - `regex_token_iterator`: Iterate over non-matches.
