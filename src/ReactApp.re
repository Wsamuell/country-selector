module App = {
  let style =
    ReactDOM.Style.make(~display="flex", ~justifyContent="center", ());

  [@react.component]
  let make = () => {
    <div style> <CountrySelect /> </div>;
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
