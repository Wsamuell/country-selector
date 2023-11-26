open ReactSelect;
open CountryData;

module Styles = {
  Js.log(Fetcher.api);
};

module App = {
  [@react.component]
  let make = () => {
    <Select multi=false />;
  };
};

ReactDOM.querySelector("#root")
->(
    fun
    | Some(root) => ReactDOM.render(<App />, root)
    | None =>
      Js.Console.error(
        "Failed to start React: couldn't find the #root element",
      )
  );
