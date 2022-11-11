//
// Created by yuri on 22-11-10.
//

#ifndef LOG_YURI_H
#define LOG_YURI_H

#include <fstream>
#include <vector>
#include <memory>

namespace yuri
{


using std::make_unique;
using std::unique_ptr;
using std::vector;

template <typename... Args> void log(Args&&... args);

void log(vector<int> &v);

template <typename T> void outFile(std::fstream& fst, T&& value);


template <typename T, typename... Args>
void outFile(std::fstream& fst, T&& value, Args&&... args);

inline void getData();

//     存储数据类

    class Data {
    private:
        int row = 0;
	    int col = 0;
	    unique_ptr<vector<vector<int>>> data = nullptr;
	    
    public:
	    Data() = default;
	    ~Data() = default;
	    
	    Data(std::fstream& fst)
	    {
		    fst >> row >> col;
		    data = make_unique<vector<vector<int>>>(row, vector<int>(col));
		    for (int i = 0; i < row; i++) {
			    for (int j = 0; j < col; j++) {
				    fst >> (*data)[i][j];
                }
            }
	    }
	    Data(int row, int col)
	    {
		    this->row = row;
		    this->col = col;
		    data = make_unique<vector<vector<int>>>(row, vector<int>(col));
	    }

	    vector<vector<int>>& getData()
	    {
		    std::fstream fst;
		    fst.open("in.txt", std::ios::in);
		    fst >> row >> col;
		    data = make_unique<vector<vector<int>>>(row, vector<int>(col));
		    for (int i = 0; i < row; i++) {
			    for (int j = 0; j < col; j++) {
				    fst >> (*data)[i][j];
                }
		    }
		    fst.close();
		    return *data;
	    }

	    vector<vector<int>>& getData(int row, int col)
	    {
		    this->row = row;
		    this->col = col;
		    data = make_unique<vector<vector<int>>>(row, vector<int>(col));
		    return *data;
	    }

	    vector<vector<int>>& getData(int row, int col, int k)
	    {
		    this->row = row;
		    this->col = col;
		    data = make_unique<vector<vector<int>>>(row, vector<int>(col,k));
		    return *data;
        }

	    void outData()
	    {
		    row = data->size();
		    col = (*data)[0].size();
		    std::fstream fst;
            fst.open("./out.txt", std::ios::app);
            if (!fst.is_open()) {
                fst.open("./out.txt", std::ios::out);
            }
		    for (int i = 0; i < row; i++) {
			    for (int j = 0; j < col; j++) {
				    fst << (*data)[i][j] << " ";
			    }
			    fst << "\n";
		    }
		    fst.close();
        }
    };


    //     写入数据
    template<typename T>
    void outFile(std::fstream &fst, T &&value) {
        fst << value << std::endl;
        fst.close();
    }

    template<typename T, typename ...Args>
    void outFile(std::fstream &fst, T &&value, Args &&...args) {
        fst << value << " ";
        outFile(fst, args...);
    }

    //     接受数据
    template<typename ...Args>
    void log(Args &&...args) {
        std::fstream fst;
        fst.open("./out.txt", std::ios::app);
        if (!fst.is_open()) {
            fst.open("./out.txt", std::ios::out);
        }
        outFile(fst, args...);
    }

    inline void log(vector<int>& v)
    {
	    std::fstream fst;
        fst.open("./out.txt", std::ios::app);
        if (!fst.is_open()) {
            fst.open("./out.txt", std::ios::out);
        }
	    for (int x: v) {
		    fst << x << " ";
	    }
	    fst << "\n";
    }

    inline void clear_log()
    {
	    std::fstream fst;
	    fst.open("./out.txt", std::ios::out);
	    fst.close();
    }

}


#endif //LOG_YURI_H
