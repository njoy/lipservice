struct Tc {
  using Value_t = double;
  static std::string name(){ return "tc"; }

  static std::string description(){ 
    return 
        "The tc argument specifies the temperature (in eV) of the fast \n"
        "spectrum when calculating a weight function.";
  }

  static bool verify( const Value_t T ){ return T > 0.0; }
};
