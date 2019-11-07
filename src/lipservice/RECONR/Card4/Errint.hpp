struct Errint {
  using Value_t = double;
  static std::string name(){ return "errint"; }

  static std::string description(){
    return
        "The errint argument specifies the maximum resonance-integral error \n"
        "(in barns) per grid point.\n"
        "\n"
        "errint must be > 0. The default value is err/2E4.";
  }

  static Value_t
  defaultValue( const Argument< Err >& err ){ return (err.value / 2E4); }

  static bool
  verify( const Value_t& e, const Argument< Err >& ){ return e > 0.0; }
};
