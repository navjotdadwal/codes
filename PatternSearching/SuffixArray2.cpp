// suffixArray[i] represents the position of string starting from i in the sorted array
#define FILL(a, val) memset((a), (val), sizeof(a));
namespace SuffixArray
{
    const int MAXSIZE = 200100;
    const int ALPHABET = 128;
    int p[MAXSIZE], c[MAXSIZE], cnt[MAXSIZE];
    int pn[MAXSIZE], cn[MAXSIZE];
    vector<int> getSuffixArray(string& s)
    {
        FILL(cnt, 0);
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            ++cnt[s[i]];
        }
        for (int i = 1; i < ALPHABET; ++i)
        {
            cnt[i] += cnt[i-1];
        }
        for (int i = 0; i < n; ++i)
        {
            p[--cnt[s[i]]] = i;
        }
        int count = 1;
        c[p[0]] = count-1;
        for (int i = 1; i < n; ++i)
        {
            if (s[p[i]] != s[p[i-1]])
                ++count;
            c[p[i]] = count - 1;
        }
        for (int h = 0; (1<<h) < n; ++h)
        {
            for (int i = 0; i < n; ++i)
            {
                pn[i] = p[i] - (1<<h);
                if (pn[i] < 0)
                    pn[i] += n;
            }
    
            FILL(cnt, 0);
    
            for (int i = 0; i < n; ++i)
            {
                ++cnt[c[i]];
            }
            for (int i = 1; i < count; ++i)
            {
                cnt[i] += cnt[i-1];
            }
            for (int i = n-1; i >= 0; --i)
            {
                p[--cnt[c[pn[i]]]] = pn[i];
            }
            count = 1;
            cn[p[0]] = count-1;
            for (int i = 1; i < n; ++i)
            {
                int pos1 = (p[i] + (1<<h))%n;
                int pos2 = (p[i-1] + (1<<h))%n;
                if (c[p[i]] != c[p[i-1]] || c[pos1] != c[pos2])
                    ++count;
                cn[p[i]] = count - 1;
            }
            for (int i = 0; i < n; ++i)
            {
                c[i] = cn[i];
            }
        }
        vector<int> res;
        res.reserve(n);
        for (int i = 0; i < n; ++i)
        {
            res.push_back(c[i]);
        }
        return res;
    }
}
vector<int> suffixArray = SuffixArray::getSuffixArray(s);
