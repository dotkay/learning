(* minimum missing natural number *)
let min_missing_num lst = 
  let sort_lst = List.sort compare lst in
  let rec find sort_lst = 
    match sort_lst with
    | [] -> None
    | x::[] -> Some(x+1)
    | x::y::_ when y - x > 1 -> Some (x+1)
    | _::tl -> find tl
  in
  find ((-1)::sort_lst);;
