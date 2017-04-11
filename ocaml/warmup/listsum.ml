(* compute the sum of all elements of a list recursively *)

let rec sum lst = 
  match lst with
  | [] -> 0
  | h::t -> h + sum t;;

(* test program *)

let () = 
  let l1 = [1;2;3;4;5] in
  Printf.printf "Sum of elements in the list: %d\n" (sum l1);;
