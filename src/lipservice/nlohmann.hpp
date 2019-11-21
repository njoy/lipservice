// Taken from https://github.com/nlohmann/json#arbitrary-types-conversions
namespace nlohmann{

template< typename T >
struct adl_serializer< optional< T > > {
    static void to_json( json& j, const optional<T>& opt ) {
        if ( not opt ) {
            j = nullptr;
        } else {
          j = *opt; // this will call adl_serializer<T>::to_json which will
                    // find the free function to_json in T's namespace!
        }
    }

    static void from_json( const json& j, optional< T >& opt ) {
        if ( j.is_null() ) {
            opt = nullptr;
        } else {
            opt = j.get< T >(); // same as above, but with
                              // adl_serializer<T>::from_json
        }
    }
};

} // namespace nlohmann
