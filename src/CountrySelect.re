open Bindings;
open CountryData;
open Icons;
open SharedStyle;

module Style = {
  let wrapper =
    ReactDOM.Style.make(
      ~width="230px",
      ~height="429px",
      ~fontFamily="Arial",
      ~fontSize="14px",
      (),
    );
  let dropdown =
    ReactDOM.Style.make(~width="30%", ~color=colorToHex(Light), ());
  let selectContainer =
    ReactDOM.Style.make(~paddingTop="4px", ~borderRadius="2px", ());
  let button =
    ReactDOM.Style.make(
      ~display="flex",
      ~height="26px",
      ~padding="4px 10px",
      ~alignItems="center",
      ~borderRadius="3px",
      ~minWidth="141px",
      ~justifyContent="space-between",
      ~border=
        "1px solid var(--light-border-control-alpha, rgba(0, 0, 0, 0.20))",
      ~background="#FFFFFF",
      (),
    );
  let flag =
    ReactDOM.Style.make(
      ~backgroundSize="contain",
      ~backgroundPosition="50%",
      ~backgroundRepeat="no-repeat",
      (),
    );
  let icon = {
    ReactDOM.Style.make(~padding="3px", ());
  };
};

// module Control = {
//   [@react.component]
//   let make = (~children: React.element) => {
//     // Destructure props using the ReasonML syntax
//     let children: React.element = children;

//     // Render the custom Control component
//     <div> <span> <Search style=Style.icon /> children </span> </div>;
//   };
// };
// let components: Select.reactSelectComponents = {control: Control.make};

[@react.component]
let make = () => {
  let (active, setActive) = React.useState(() => false);
  let (countries, setCountries) =
    React.useState(() => countryLoadState(None));
  let (selectedCountry, setSelectedCountry) =
    React.useState(() => {label: "Select A country", value: "xx"});
  React.useEffect1(
    () => {
      let _ =
        Js.Promise.(
          Fetch.fetch(url)
          |> then_(Fetch.Response.json)
          |> then_(json => json |> decode |> resolve)
          |> then_(itemArray =>
               countryLoadState(Some(itemArray)) |> resolve
             )
          |> then_(array => setCountries(_ => array) |> resolve)
        );
      Some(() => ());
    },
    [||],
  );
  <div style=Style.wrapper>
    <button onClick={_ => setActive(_ => !active)} style=Style.button>
      <span className={"fi fi-" ++ selectedCountry.value} />
      <div style=Style.flag> {React.string(selectedCountry.label)} </div>
      <Arrow style=Style.icon />
    </button>
    {active
     |> (
       fun
       | true =>
         <div style=Style.selectContainer>
           <Select
             closeMenuOnSelect=true
             //  components
             multi=false
             name="Country Selector"
             noOptionsMessage={_ => "Country Not Found!"}
             onChange={value => {
               setSelectedCountry(_ => value);
               setActive(_ => false);
             }}
             options=countries
             placeholder="Search"
             styles=Style.dropdown
           />
         </div>

       | false => React.null
     )}
  </div>;
};
