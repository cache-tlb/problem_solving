/*#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
    int mem, cpu;
    int reach_time, time_line;
    int reward, bonus, punishment;
    Job(){}
    Job(int Ai,int Bi,int Ti,int Ui,int Vi,int Wi,int Xi)
        :cpu(Ai),mem(Bi),reach_time(Ti),time_line(Ui),reward(Vi),bonus(Wi),punishment(Xi){}
};

// M: CPU, N: mem, L:jobs
int N, M, L;
int F;
vector<Job> jobs;

bool cmp(const Job &a, const Job &b){
    return (a.reach_time < b.reach_time) || (a.reach_time == b.reach_time && a.reward > b.reward);
}

bool operator < (const Job &a, const Job &b){
    return cmp(a,b);
}

int process(){
    vector<Job> exe_jobs;
    set<Job> wait_jobs;
    int timeline = 0, pos = 0;
    int sum = 0;

    while(timeline < F){
        if(wait_jobs.empty()){
            if(pos < jobs.size() && jobs[pos].reach_time < F)
                timeline = jobs[pos].reach_time;
            else break;
            //cout << timeline << endl;
            while(pos < jobs.size() && jobs[pos].reach_time == timeline){
                Job job = jobs[pos++];
                if (job.cpu <= M && job.mem <= N) {
                    M -= job.cpu;
                    N -= job.mem;
                    exe_jobs.push_back(job);
                }
                else{
                    wait_jobs.insert(job);
                }
            }
            timeline++;
        }
        else{
            for(set<Job>::iterator it = wait_jobs.begin(); it != wait_jobs.end(); it++){
                if(it->cpu <= M && it->mem <= N){
                    M -= it->cpu;
                    N -= it->mem;
                    exe_jobs.push_back(*it);
                }
            }
            for(int i = 0; i < exe_jobs.size(); i++){
                wait_jobs.erase(exe_jobs[i]);
            }
            while(pos < jobs.size() && jobs[pos].reach_time == timeline){
                Job &job = jobs[pos++];
                if (job.cpu <= M && job.mem <= N) {
                    M -= job.cpu;
                    N -= job.mem;
                    exe_jobs.push_back(job);
                }
                else{
                    wait_jobs.insert(job);
                }
            }
            timeline++;
        }
        //

    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    while(scanf("%d", &F) != EOF){
        if(!F) break;
        if(t) printf("\n");
        scanf("%d%d%d", &M, &N, &L);
        jobs.resize(L);
        for(int i = 0; i < L; i++){
            int Ai, Bi, Ti, Ui, Vi, Wi, Xi;
            scanf("%d%d%d%d%d%d%d", &Ai, &Bi, &Ti, &Ui, &Vi, &Wi, &Xi);
            jobs[i] = Job(Ai, Bi, Ti, Ui, Vi, Wi, Xi);
        }
        sort(jobs.begin(), jobs.end(), cmp);
        printf("Case %d: %d\n", ++t, process());
    }
    return 0;
}
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
    int mem, cpu;
    int reach_time, time_line;
    int reward, bonus, punishment;
    int flag, start_time;
    Job(){}
    Job(int Ai,int Bi,int Ti,int Ui,int Vi,int Wi,int Xi)
        :cpu(Ai),mem(Bi),reach_time(Ti),time_line(Ui),reward(Vi),bonus(Wi),punishment(Xi),flag(0){}
};

// M: CPU, N: mem, L:jobs
int N, M, L;
int F;
vector<Job> jobs;

bool cmp(const Job &a, const Job &b){
    return (a.reach_time < b.reach_time) || (a.reach_time == b.reach_time && a.reward > b.reward);
}

int process(){
    int timeline = 0, pos = 0;
    int sum = 0;

    for(; timeline <= F; timeline++){
        for(int i = 0; i < L; i++){
            if(jobs[i].flag == 0 && jobs[i].start_time + 1 == timeline){
                M += jobs[i].cpu;
                N += jobs[i].mem;
                jobs[i].flag = -1;
            }
        }

        for(int i = 0; i < L; i++){
            if(jobs[i].reach_time > timeline) break;
            if(jobs[i].flag == 1 && jobs[i].cpu <= M && jobs[i].mem <= N){
                M -= jobs[i].cpu;
                N -= jobs[i].mem;
                jobs[i].flag = 0;
                jobs[i].start_time = timeline;
            }
        }
        //
    }

    for(int i = 0; i < L; i++){
        if(jobs[i].flag == -1){
            if(jobs[i].start_time + 1 > jobs[i].time_line){
                sum += jobs[i].reward - jobs[i].punishment*(jobs[i].start_time + 1 - jobs[i].time_line);
            }
            else{
                sum += jobs[i].reward + jobs[i].bonus*(jobs[i].time_line - jobs[i].start_time - 1);
            }
        }
        if(jobs[i].flag == 0){
            if(jobs[i].time_line <= F){
                sum -= (F - jobs[i].time_line)*jobs[i].punishment;
            }
        }
        if(jobs[i].flag == 1){
            if(jobs[i].time_line <= F){
                sum -= (F - jobs[i].time_line)*jobs[i].punishment;
            }
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    while(scanf("%d", &F) != EOF){
        if(!F) break;
        scanf("%d%d%d", &M, &N, &L);
        jobs.resize(L);
        for(int i = 0; i < L; i++){
            int Ai, Bi, Ti, Ui, Vi, Wi, Xi;
            scanf("%d%d%d%d%d%d%d", &Ai, &Bi, &Ti, &Ui, &Vi, &Wi, &Xi);
            jobs[i] = Job(Ai, Bi, Ti, Ui, Vi, Wi, Xi);
            jobs[i].start_time = -2;
            jobs[i].flag = 1;
        }
        sort(jobs.begin(), jobs.end(), cmp);
        printf("Case %d: %d\n\n", ++t, process());
    }
    return 0;
}
