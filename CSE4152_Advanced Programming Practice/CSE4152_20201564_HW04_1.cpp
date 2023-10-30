#include "EnvGame.h"

vector<int> solve(EnvGame &a)
{
    // std::cout << "\n";
    int n = a.getNodeN();
    int i, j, k, tmpa, tmpb, tmpc, ni;
    bool light = false;
    bool cur = true; // true:A false:B
    vector<int> ans;
    vector<int> ansb;

    ans.resize(n);
    ansb.resize(n);
    for (i = 0; i < n; i++)
    {
        ans[i] = -1;
        ansb[i] = -1;
    }

    for (i = 0; i < n / 3 * 3; i++)
    {
        if (ans[i] != -1)
            continue;
        for (j = 0; j < n; j++)
        {
            if (j != i && ans[j] == -1)
            {
                ni = j;
                break;
            }
        }
        // cout << "1. connect " << i << " " <<ni << "\n";
        a.cleanAllWires();
        a.connectWire(i, ni);
        a.goToOtherSide();
        light = false;
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (j != k && ansb[j] == -1 && ansb[k] == -1)
                {
                    light = a.checkConnectivity(j, k);
                    if (light)
                    {
                        // cout << "2. light on "<< j << " " << k << "\n";
                        a.cleanAllWires();
                        tmpc = j;
                        break;
                    }
                }
            }
            if (light)
                break;
        }
        for (j = 0; j < n; j++)
        {
            if (ansb[j] == -1 && j != k && tmpc != j)
            {
                // cout << "3. B connnect " << j << " " <<k <<"\n";
                a.connectWire(j, k);
                tmpa = j;
                tmpb = k;
                break;
            }
        }
        light = false;
        // cout << "3.5 tmpa " << tmpa << " tmpb " << tmpb << " tmpc " << tmpc <<"\n";
        a.goToOtherSide();
        for (j = 0; j < n; j++)
        {
            if (ans[j] == -1 && i != j)
            {
                light = a.checkConnectivity(i, j);
                if (i != j && ni != j && light)
                {
                    // cout << "4-1. a light on " << i << " " <<j <<"\n";
                    ans[i] = tmpb;
                    ansb[tmpb] = i;
                    ans[j] = tmpa;
                    ansb[tmpa] = j;
                    ans[ni] = tmpc;
                    ansb[tmpc] = ni;
                    break;
                }
            }
        }
        light = false;
        for (j = 0; j < n; j++)
        {
            if (ans[j] == -1 && ni != j)
            {
                light = a.checkConnectivity(ni, j);
                if (i != j && ni != j && light)
                {
                    // cout << "4-2. a light on " << ni << " " <<j <<"\n";
                    ans[ni] = tmpb;
                    ansb[tmpb] = ni;
                    ans[j] = tmpa;
                    ansb[tmpa] = j;
                    ans[i] = tmpc;
                    ansb[tmpc] = i;
                    break;
                }
            }
        }

        /*std::cout << "\n";
        for(int g=0; g<n; g++)
        {
            std::cout << ans[g] << " ";
        }
        std::cout << "\n";
        for(int g=0; g<n; g++)
        {
            std::cout << ansb[g] << " ";
        }
        std::cout << "\n\n";*/
    }

    if (n % 3 == 1)
    {
        for (i = 0; i < n; i++)
        {
            if (ans[i] == -1)
            {
                for (j = 0; j < n; j++)
                {
                    if (ansb[j] == -1)
                    {
                        ans[i] = j;
                        return ans;
                    }
                }
            }
        }
    }
    else if (n % 3 == 2)
    {
        a.cleanAllWires();
        for (i = 0; i < n; i++)
        {
            if (ans[i] == -1)
            {
                for (j = 0; j < n; j++)
                {
                    if (i != j && ans[j] != -1)
                    {
                        a.connectWire(i, j);
                        tmpa = i;
                        tmpb = j;
                        break;
                    }
                }
                break;
            }
        }
        light = false;
        a.goToOtherSide();
        for (i = 0; i < n; i++)
        {
            if (ansb[i] == -1)
            {
                for (j = 0; j < n; j++)
                {
                    if (j != i && ansb[j] != -1)
                    {
                        light = a.checkConnectivity(i, j);
                        if (light)
                        {
                            ans[tmpa] = i;
                            ansb[i] = tmpa;
                            break;
                        }
                    }
                }
                if (light)
                    break;
            }
        }
        for (i = 0; i < n; i++)
        {
            if (ans[i] == -1)
            {
                for (j = 0; j < n; j++)
                {
                    if (ansb[j] == -1)
                    {
                        ans[i] = j;
                        return ans;
                    }
                }
            }
        }
    }
    return ans;
}
