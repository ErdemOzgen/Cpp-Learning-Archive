### Parallel Algorithms
- **parallel execution**: tasks are done on multiple threads (often running on several processor cores)
- **vectorized execution**: tasks are done on a single thread using vectorization, also known as SIMD (“Single Instruction, Multiple Data”).

STL offers support for *both* and we can be specific about wanting sequential execution; in `<execution>`, we find:
- `seq`: sequential execution
- `par`: parallel execution (if feasible)
- `par_unseq`: parallel and/or unsequenced (vectorized) execution (if feasible).

Consider `std::sort()`:
- `sort(v.begin(), v.end());` sequential
- `sort(seq, v.begin(), v.end());` sequential (same as the default)
- `sort(par, v.begin(), v.end());` parallel
- `sort(par_unseq, v.begin(), v.end());` parallel and/or vectorized


Whether it is worthwhile to parallelize and/or vectorize depends on the algorithm, the number of elements in the sequence, the hardware, and the
utilization of that hardware by programs running on it. Consequently, the execution policy indicators are just hints. A compiler and/or run-time scheduler will decide how much concurrency to use. This is all nontrivial and the rule against making statements about efficiency without measurement is very important here.