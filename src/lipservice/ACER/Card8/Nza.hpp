struct Nza {
  using Value_t = int;
  static std::string name(){ return "nza"; }

  static std::string description(){
    return 
      "The nza parameter specifies the number of ZA values that will be\n "
      "provided in Card8a.";
  }

  static Value_t defaultValue(){ return 3; }
  static bool verify( const Value_t& n ){ 
    return ( n > 0 ) and ( n <= 16 );
  }
};
