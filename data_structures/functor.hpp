struct f{
    friend bool operator< (const f& lhs, const f& rhs){ return lhs.priority < rhs.priority; }

    friend bool operator> (const f& lhs, const f& rhs){ return rhs < lhs; }
    friend bool operator<=(const f& lhs, const f& rhs){ return !(lhs > rhs); }
    friend bool operator>=(const f& lhs, const f& rhs){ return !(lhs < rhs); }
    operator int() const { return priority; }
    unsigned int priority=10;
    void (*action)();
};