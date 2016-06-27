#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>

using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;
using std::pair;
using namespace std;

typedef long long llong;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;
  vector<pair<int, llong>> schedule_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  int LeftChild(int i)
  {
      return 2 * i + 1;
  }

  int RightChild(int i)
  {
      return 2 * i + 2;
  }

  pair<int, llong> GetMax()
  {
      return schedule_[0];
  }

  /** heap invaraint

  */
  void SiftDown(int i)
  {
      int mI = i;
//      cout << " mI  = " << mI << endl;
      int l = LeftChild(i);
      int r = RightChild(i);
      if (l < schedule_.size() && r < schedule_.size())
      {
          /// check if left and right have the same value, if so need to 
          /// keep invariant that left index is smaller than the right index
          if (schedule_[l].first > schedule_[r].first && schedule_[l].second == schedule_[r].second)
              swap(schedule_[l], schedule_[r]);
      }
      /// second invariant, parent needs to be smaller than any child
      if (l < schedule_.size())
      {
          if (schedule_[i].second > schedule_[l].second)
              mI = l;
      }
  //    cout << " l = " << l << endl;
      if (r < schedule_.size())
      {
          if (schedule_[r].second < schedule_[mI].second)
          {
              mI = r;
      //        cout << (r < schedule_.size()) << endl;
      //        cout << "mI = " << mI << endl;
          }
      }
    //  cout << "r = " << r << " size = " << schedule_.size() << endl;
    //  cout << "i = " << i << " mI = " << mI << endl;
      if (i != mI){
          swap(schedule_[i], schedule_[mI]);
          SiftDown(mI);
      }
      else
      {
          /// the third invariant
          /// if all have the same value, parent index should be smaller than the children's
          if (l < schedule_.size() && schedule_[i].first > schedule_[l].first && schedule_[i].second == schedule_[l].second)
              swap(schedule_[i], schedule_[l]);
      }
  }

  void MakeHeap()
  {
      for (int i = floor(schedule_.size() / 2); i >= 0; i--)
          SiftDown(i);
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    if (num_workers_ == 0)
        return;
    vector<long long> next_free_time(num_workers_, 0);
    schedule_.resize(num_workers_, make_pair<int,int>(0,0));
    int i = 0;
    for (auto& p : schedule_)
        p.first = i++;

   // cout << schedule_.size() << endl;

    for (int i = 0; i < jobs_.size(); ++i) {
        int duration = jobs_[i];
        std::pair<int, llong> next_worker = GetMax();
        start_times_[i] = next_worker.second;
        assigned_workers_[i] = next_worker.first;

        schedule_[0].second += (llong)duration;
        SiftDown(0);

//        cout << "schedule : "; 
//        for (auto& p : schedule_)
//            cout << p.first << " " << p.second << "; "; 
//        cout << endl;

        MakeHeap();
    }
  }

  void oldAssignJobs() {
      // TODO: replace this code with a faster algorithm.
      assigned_workers_.resize(jobs_.size());
      start_times_.resize(jobs_.size());
      vector<long long> next_free_time(num_workers_, 0);
      for (int i = 0; i < jobs_.size(); ++i) {
          int duration = jobs_[i];
          int next_worker = 0;
          for (int j = 0; j < num_workers_; ++j) {
              if (next_free_time[j] < next_free_time[next_worker])
                  next_worker = j;
          }
          assigned_workers_[i] = next_worker;
          start_times_[i] = next_free_time[next_worker];
          next_free_time[next_worker] += duration;
      }
  }

public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
