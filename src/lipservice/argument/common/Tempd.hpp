struct Tempd {
  using Value_t = double;
  static std::string name(){ return "tempd"; }

  static std::string description(){
    return 
        "The tempd argument specifies the absolute temperature (in kelvin)\n"
        "for the material to be processed.";
  }

  static Value_t defaultValue(){ return 300; }
  static bool verify( const Value_t& t ){ return t >= 0.0; }
};
