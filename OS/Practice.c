for(i=0;i<f;i++)
{
    m[i]  = -1;
    ct[i] = 0;
}

for(i=0;i<n;i++)
{

        for(j=0;j<f;j++)
        {
            if(m[j]== rs[i])
            {
                flag[i] = 1;
                ct[j] = next;
                next++
            }
        }

        if(flag[i] == 0)
        {
            if(i<f)
            {
                m[i] = rs[i];
                ct[i] = next;
                next++;
            }
            else{
                min =0;
                for(j=0;j<f;j++)
                {
                    if(ct[min] > ct[j])
                    {
                        min=j;
                    }

                    m[min] = rs[i];
                    ct[min] = next;
                    next++;               
                 }
            }
            pf++;
        }
}