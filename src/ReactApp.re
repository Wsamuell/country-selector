// open ReactSelect;

// let test = Select.make(~multi=false);
// Js.log(test);
module App = {
  [@react.component]
  let make = () => {
    <div>
       {React.string("Hello World")} </div>;
      // <div> <Select. multi=false /> </div>
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
