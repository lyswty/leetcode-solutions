class Solution:
    def complexNumberMultiply(self, a: str, b: str) -> str:
        plus_a, plus_b, i_a, i_b = a.index("+"), b.index("+"), a.index("i"), b.index("i")
        a1, a2, b1, b2 = int(a[0:plus_a]), int(a[plus_a + 1:i_a]), int(b[0:plus_b]), int(b[plus_b + 1:i_b])
        res1, res2 = a1 * b1 - a2 * b2, a1 * b2 + a2 * b1
        res = "%d+%di" %(res1, res2)
        return res
