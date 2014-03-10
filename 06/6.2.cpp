template <typename ValueType, size_t N>
class Arrary {
public:
    bool read(size_t i, ValueType* v) const {
        if (isValid(i)) {
            *v = A_[i];
            return true;
        }
        return false;
    }

    void write(size_t i, const ValueType& v)  {
        if (!isValid(i)) {
            S_[t_] = i;
            P_[i] == t_++;
        }
        A_[i] = v;
    }

private:
    bool isVlid(size_t i) const {
        return 0 <= P_[i] && P_[i] < t_ && S_[P_[i]] == i;
    }
    ValueType A_[N];
    int P_[N], S_[N], t_ = 0;
};