struct Iza {
  using Value_t = std::vector< int >;
  static std::string name(){ return "iza"; }

  static std::string description(){
    return
      "The iza argument specifies the ZA values for the moderator components.";
  }

  static bool verify( const Value_t& M, const int ){ 
    if( M.size() < 1 ){
      Log::error( "No iza values were given." );
      return false;
    }

    for( const auto& iza : M ){
      if( iza < 1 ){
        Log::error( "iza values must be greater than 0." );
        Log::info( "given iza value of: {}", iza );
        return false;
      }
      if( iza > 199999 ){
        Log::error( "iza values must be less than 200000" );
        Log::info( "given iza value of: {}", iza );
        return false;
      }
    }
    return true;
  }
};
