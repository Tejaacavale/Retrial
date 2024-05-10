 #include <bits/stdc++.h>
    #include <fstream>
    using namespace std;
    #define int long long
    #define pb push_back
    #define mp make_pair
    #define eb emplace_back
    #define F first
    #define S second
    #define sp " "
    // #define pair<double,double>
    double generate_exponential(double lambda)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::exponential_distribution<double> dist(lambda);
        return dist(gen);
    }
     
    int32_t main()
    {
        int no_jobs;
        std::ofstream file1("file1.txt");
        std::ofstream file2("file2.txt");
        std::ofstream file3("file3.txt");
 
          if (!file1.is_open() || !file2.is_open() || !file3.is_open()) {
            std::cerr << "Error opening files!" << std::endl;
            return 1;
        }
        double iat_rate, st_rate, nu_rate, rho;
        cout << "Enter number of jobs: ";
        cin >> no_jobs;
        cout << "Enter Job Arrival Rate: ";
        cin >> iat_rate;
     
        cout << "Enter Job Service Rate: ";
        cin >> st_rate;
     
        cout << "Enter Re-trial Rate: ";
        cin >> nu_rate;
        double s_busy = 0;
        double s_busy_till = 0;
        //   double s_busy_wo = 0;
        set<pair<pair<double, double>, pair<double, int>>> myset;
        set<pair<pair<double, double>, pair<double, int>>> tempset;
        vector<pair<pair<double, double>, pair<double, int>>> completed_list;
        rho = iat_rate / st_rate;
        double prev = 0;
        double avg1 = 0;
        for (int i = 0; i < no_jobs; i++)
        {
            double x1 = generate_exponential(iat_rate);
            avg1 += (x1 / no_jobs);
            myset.insert(mp(mp(x1 + prev, x1 + prev), mp(0, 0)));
            prev += x1;
        }
        cout << avg1 << endl;
        while (myset.size() > 0)
        {
            if (s_busy)
            {
                int count = myset.size();
                while (count != 0)
                {
                    count = 0;
                    for (auto i : myset)
                    {
                        pair<pair<double, double>, pair<double, int>> j;
                        j = i;
                        if (i.first.first < s_busy_till)
                        {
                            count++;
                            double x2 = generate_exponential(nu_rate);
                            // cout << x2 << endl;
     
                            j.first.first += x2;
                            j.second.second += 1;
                            tempset.insert(j);
                        }
                        else
                        {
                            tempset.insert(j);
                        }
                        //   cout<<endl;
                    }
                    myset.clear();
                    myset = tempset;
                    tempset.clear();
                }
                s_busy = 0;
            }
            if (!s_busy)
            {
                // cout << "hi" <<  endl;
                pair<pair<double, double>, pair<double, int>> mypair;
                double x3 = generate_exponential(st_rate);
                for (auto i : myset)
                {
                    mypair = i;
                    break;
                }
                myset.erase(myset.find(mypair));
                s_busy_till = mypair.first.first + x3;
                mypair.second.first = s_busy_till;
                s_busy = 1;
                completed_list.pb(mypair);
            }
        }
        double avg_time_server = 0;
        double avg_time_total = 0;
     
        for (auto i : completed_list)
        {
            avg_time_server += ((i.first.first - i.first.second) / no_jobs);
            avg_time_total += ((i.second.first - i.first.second) / no_jobs);
    //  file1 << "This is data for file 1." << std::endl;
            file1 << i.first.first << sp << i.first.second << sp << i.second.first << sp << i.second.second << endl;
     
            // cout << i.first.first << sp << i.first.second << sp << i.second.first << sp << i.second.second << endl;
        }
        file2<<no_jobs<<sp<<iat_rate<<sp<<st_rate<<sp<<nu_rate<<endl;
        file2 << avg_time_server<<sp<<avg_time_total << endl;
        double sum_nt=0;
        double sum_nonblock=0;
        for(int i=0;i<completed_list.size();i++){
            if(i!=0){
                sum_nonblock+=(completed_list[i].first.first-completed_list[i-1].second.first);
            }
        }
        file2<<sum_nonblock/no_jobs<<endl;
     
        for(int i=0;i<completed_list.size();i++){
            sum_nt+=(completed_list[i].second.first-completed_list[i].first.second);
        }
        file2<<sum_nt/completed_list[completed_list.size()-1].second.first<<endl;
         double lastsum=0;
    int n=completed_list.size();
    for(int i=0;i<n-1;i++){
        double mini=1e15;
        for(int j=0;j<n;j++){
            if(completed_list[i].second.first<completed_list[j].first.second){
                mini=min(mini,completed_list[j].first.second);
            }
             if(completed_list[i].second.first<completed_list[j].first.first){
                mini=min(mini,completed_list[j].first.first);
            }
        }
        if(mini!=1e15){
            lastsum+=(mini-completed_list[i].second.first);
        }
            file3<<1-(lastsum/completed_list[i].second.first)<<endl;
    }
    file3<<1-(lastsum/completed_list[n-1].second.first)<<endl;
        return 0;
    }