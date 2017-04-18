// http://chuansong.me/n/2702172
#define MAKE_PAIR(text) std::pair{#text, text}
template
constexpr static inline auto apply(T const & args)
{
    return args;
}

template
constexpr static inline auto apply(T const & t, const T1& first, const Args&... args)
{
    return apply(std::tuple_cat(t, std::make_tuple(MAKE_PAIR(first))), args...);
}

#define META(...) auto meta(){ return apply(std::tuple<>(), __VA_ARGS__); }
