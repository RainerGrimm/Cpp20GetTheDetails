template<typename T>
concept range = requires(T& t) {
    ranges::begin(t);
    ranges::end(t);
};


template<typename T>
concept view = range<T> &&
               movable<T> &&
               enable_view<T>;


template<class T
inline constexpr bool enable_view = derived_from<T, view_base>;