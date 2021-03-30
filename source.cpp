#include <bits/stdc++.h>
using namespace std;
class MovieReview{
    private:
        map<string,pair<int,string>>movies;
        map<string,int>users;
        map<string,int>critics;
        map<pair<string,string>,int>reviews;
        map<string,pair<int,int>>moviereview;
        map<int,pair<int,int>>yearreview;
        map<string,int>rating;
        int currentyear;
        static bool cmp(pair<string, int>& a, pair<string, int>& b){
	        return a.second < b.second;
        }


        void sorrt(map<string, int>& M, vector<string>&ans){
            vector<pair<string, int> > A;

        	for (auto& it : M) {
        		A.push_back(it);
        	}
	        sort(A.begin(), A.end(), cmp);
        
	        for (auto& it : A) {
		        ans.push_back(it.first);
		       
	        }

        }
    public:
        MovieReview(){
            movies.clear();
            users.clear();
            reviews.clear();
            moviereview.clear();
            yearreview.clear();
            rating.clear();
	    time_t t = time(NULL);
	    tm* timePtr = localtime(&t);
	    currentyear=timePtr->tm_year+1900;
        }
        
        void AddMovie(string Movie, int Year, string Genre){
            movies[Movie]=make_pair(Year,Genre);
        }
        
        void AddUser(string User){
            users.insert({User,0});
        }
        
        void AddReview(string User, string Movie, int Rating){
            try{
                int year=movies[Movie].first;
                if(reviews.find(make_pair(User,Movie))!=reviews.end()){
                    throw "Multiple Reviews Not Allowed";
                
                }
                else if(year>=currentyear){
                    throw "Movie Yet to be released";
                }
                else if(Rating>10||Rating<1){
                    throw "Rating should be between 1 to 10";
                }
                else{
                    
                    if(critics.find(User)!=critics.end()){
                        reviews.insert({make_pair(User,Movie),2*Rating});
                        rating[Movie]+=2*Rating;
                        critics[User]++;
                        yearreview[year].first+=2*Rating;
                        yearreview[year].second++;
                        moviereview[Movie].first+=2*Rating;
                        moviereview[Movie].second++;
                    }
                        
                    else{
                        reviews.insert({make_pair(User,Movie),Rating});
                        yearreview[year].first+=Rating;
                        yearreview[year].second++;
                        moviereview[Movie].first+=Rating;
                        moviereview[Movie].second++;
                        users[User]++;
                        if(users[User]>=3){
                            users.erase(User);
                            critics.insert({User,0});
                        }
                    }
                }  
            }
            catch(const char* msg){
                cout<<msg<<'\n';
            }
            
        }
        
        vector<string>TopNMovies(int n){
            vector<string>ans;
            sorrt(rating,ans);
            return ans;
        }
        
        double AverageReviewInYear(int Year){
            int ans=yearreview[Year].first;
            int count=yearreview[Year].second;
            double result=(ans*1.0)/count;
            return result;
        }
        
        double AverageReviewOfMovie(string Movie){
            int ans=moviereview[Movie].first;
            int count=moviereview[Movie].second;
            double result=(ans*1.0)/count;
            return result;
        }
};

int main() {
//     MovieReview m;
//     m.AddMovie("Don",2006,"Action");
//     m.AddMovie("Tiger",2008,"Drama");
//     m.AddMovie("Padmaavat",2006,"Comedy");
//     m.AddMovie("LunchBox",2021,"Drama");
//     m.AddMovie("Guru",2006,"Drama");
//     m.AddMovie("Metro",2006,"Romance");
//     m.AddUser("SRK");
//     m.AddUser("Salmaan");
//     m.AddUser("Deepeka");
//     m.AddReview("SRK","Don",2);
//     m.AddReview("SRK","Padmaavat",8);
//     m.AddReview("Salmaan","Don",5);
//     m.AddReview("Deepeka","Don",9);
//     m.AddReview("Deepeka","Guru",6);
//     m.AddReview("SRK","Tiger",5);
//     m.AddReview("SRK","Metro",7);
//     vector<string>ans=m.TopNMovies(3);
//     for(auto s:ans)
//     cout<<s<<'\n';
//     cout<<m.AverageReviewOfMovie("Don")<<'\n';
//     cout<<m.AverageReviewInYear(2006)<<'\n';

	return 0;
}


