module App = {
  // This sample forces an import of Belt.*, so that CI builds can ensure that
  // Melange has been installed correctly for JS bundlers to be able to find it.
  [@react.component]
  let make = () =>
    ["Hello " ++ World.name ++ "!", "This is React!"]
    ->Belt.List.map(greeting => <h1> greeting->React.string </h1>)
    ->Belt.List.toArray
    ->React.array;
};
// let id: 'a => 'a = x => x;
// make a simple drop down menu
// fetch the countries from the api
// integrate flag and write binding for it

ReactDOM.querySelector("#root")
->(
    fun
    | Some(root) => ReactDOM.render(<App />, root)
    | None =>
      Js.Console.error(
        "Failed to start React: couldn't find the #root element",
      )
  );