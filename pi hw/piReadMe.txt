
The big O order of the function was n squared. 

When I ran ___ I got ___, and it took ____.
10>>>3.44>>>0m0.009s
100>>>3.1796>>>0m0.011s
1,000>>>3.14552>>>0m0.034s
10,000>>>3.14199>>>0m1.513s

After adding constexpr, this is what I got:

When I ran ___ I got ___, and it took ____.
10>>>3.44>>>0m0.004s
100>>>3.1796>>>0m0.0.009s
1,000>>>3.14552>>>0m0.019s

I noticed that compiler took longer when using costexpr, but the actual function runs much faster. I assume this is because most of the work is being done in compile time instead of runtime.